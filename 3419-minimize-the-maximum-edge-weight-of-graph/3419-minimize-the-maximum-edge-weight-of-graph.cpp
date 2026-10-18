class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> adj[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int weight = edge[2];
            adj[node2].push_back({node1, weight});
        }
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        minHeap.push({0, 0});
        // vis[0] = 1;
        int mx = 0;
        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();
            int weight = it.first;
            int node = it.second;
            if (vis[node])
                continue;
            vis[node] = 1;
            mx = max(mx, weight);
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if (!vis[adjNode])
                    minHeap.push({wt, adjNode});
            }
        }

        for (auto it : vis) {

            if (it == 0)
                return -1;
        }

        return mx;
    }
};