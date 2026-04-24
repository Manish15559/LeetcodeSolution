class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        vector<pair<int, int>> adj[n];

        for (auto it : redEdges) {
            adj[it[0]].push_back({it[1], 0});
        }
        for (auto it : blueEdges) {
            adj[it[0]].push_back({it[1], 1});
        }
        vector<vector<int>> dist(n, vector<int>(2, 1e9));
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = 0;
        dist[0][1] = 0;
        while (!q.empty()) {
            auto it = q.front();
            int node = it.first;
            int color = it.second;
            q.pop();
            for (auto adjNode : adj[node]) {
                if (adjNode.second == color)
                    continue;
                if (dist[adjNode.first][adjNode.second] >
                    (1 + dist[node][color])) {
                    dist[adjNode.first][adjNode.second] =
                        (1 + dist[node][color]);
                    q.push({adjNode.first, adjNode.second});
                }
            }
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int mini = min(dist[i][0], dist[i][1]);
            if (mini != 1e9)
                ans[i] = mini;
        }
        return ans;
    }
};