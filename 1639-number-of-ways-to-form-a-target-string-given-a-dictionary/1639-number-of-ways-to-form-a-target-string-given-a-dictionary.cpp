class Solution {
public:
    long long way(int idx, int pos, string& target, vector<vector<int>>& count,
                  vector<vector<int>>& dp) {
        if (idx == target.size())
            return 1;
        if (pos == count[0].size())
            return 0;
        if (dp[idx][pos] != -1)
            return dp[idx][pos];
        long long ways = 0;
        int mod = 1e9 + 7;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (target[idx] == ch && count[(ch - 'a')][pos])
                ways += (count[(ch - 'a')][pos] *
                         way(idx + 1, pos + 1, target, count, dp));
            ways %= mod;
        }
        ways += way(idx, pos + 1, target, count, dp);
        ways %= mod;
        return dp[idx][pos] = ways;
    }
    int numWays(vector<string>& words, string target) {

        int n = words[0].size();
        vector<vector<int>> count(26, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (auto& word : words)
                count[(word[i] - 'a')][i]++;
        }
        int m = target.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[m][i] = 1;
        for (int idx = m - 1; idx >= 0; idx--) {
            for (int pos = n - 1; pos >= 0; pos--) {
                long long ways = 0;
                int mod = 1e9 + 7;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (target[idx] == ch && count[(ch - 'a')][pos])
                        ways += (count[(ch - 'a')][pos] * dp[idx + 1][pos + 1]);
                    ways %= mod;
                }
                ways += dp[idx][pos + 1];
                ways %= mod;
                dp[idx][pos] = ways;
            }
        }

        return dp[0][0];
    }
};