class Solution {
public:
    int dfs(int node, int parent, vector<int> adj[], int& count) {
        int tot = 0;
        int lst = -1;
        bool f = true;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            int value = dfs(it, node, adj, count);
            if (lst == -1)
                lst = value;
            else if (lst != value)
                f = false;
            tot += value;
        }
        if (f)
            count++;
        return tot + 1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count = 0;

        dfs(0, -1, adj, count);

        return count;
    }
};