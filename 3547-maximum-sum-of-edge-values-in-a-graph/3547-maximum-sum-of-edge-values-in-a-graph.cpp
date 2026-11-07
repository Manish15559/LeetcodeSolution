class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return 0;
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int leafNode = -1;
        for (int node = 0; node < n; node++) {
            if (adj[node].size() == 1) {
                leafNode = node;
                break;
            }
        }
        long long ans = n * (1ll)*(n - 1 + n - 2);
        for (int node = n - 1; node >= 1; node--) {
            long long val = 0;
            if(node>1) val=node * (1ll)*(node - 2);
            ans += val;
        }
        if (leafNode == -1)
            ans += 2;
        return ans;
    }
};