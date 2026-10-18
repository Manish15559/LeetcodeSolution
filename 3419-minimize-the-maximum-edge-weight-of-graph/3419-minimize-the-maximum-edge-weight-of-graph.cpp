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
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        minHeap.push({0, 0});
        dist[0] = 0;
        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();
            int weight = it.first;
            int node = it.second;
            if (weight > dist[node])
                continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if (dist[adjNode] > max(wt, dist[node])) {
                    dist[adjNode] = max(wt, dist[node]);
                    minHeap.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxium = 0;
        for (auto it : dist)
            maxium = max(maxium, it);

            if(maxium==1e9) return -1;

        return maxium;
    }
};