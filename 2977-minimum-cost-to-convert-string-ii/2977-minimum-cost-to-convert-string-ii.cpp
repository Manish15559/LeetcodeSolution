class Solution {
public:
    static const long long INF = 1e18;
    long long matrix[201][201];
    long long dp[1001];

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        unordered_map<string,int> mp;
        unordered_set<int> lens;

        int m = original.size();
        int n = source.size();

        // build node ids + valid lengths
        int id = 0;
        for (int i = 0; i < m; i++) {
            if (!mp.count(original[i])) {
                mp[original[i]] = id++;
                lens.insert(original[i].size());
            }
            if (!mp.count(changed[i])) {
                mp[changed[i]] = id++;
            }
        }

        // init matrix
        for (int i = 0; i < id; i++)
            for (int j = 0; j < id; j++)
                matrix[i][j] = INF;

        for (int i = 0; i < id; i++)
            matrix[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            matrix[u][v] = min(matrix[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < id; k++)
            for (int i = 0; i < id; i++)
                if (matrix[i][k] < INF)
                    for (int j = 0; j < id; j++)
                        if (matrix[k][j] < INF)
                            matrix[i][j] = min(matrix[i][j],
                                                matrix[i][k] + matrix[k][j]);

        // dp
        for (int i = 0; i <= n; i++)
            dp[i] = INF;

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // single char match
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            // try valid lengths only
            for (int L : lens) {
                if (i + L > n) continue;

                string s = source.substr(i, L);
                string t = target.substr(i, L);

                if (!mp.count(s) || !mp.count(t)) continue;

                long long d = matrix[mp[s]][mp[t]];
                if (d < INF)
                    dp[i + L] = min(dp[i + L], dp[i] + d);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
