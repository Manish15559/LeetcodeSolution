class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src] = 0;
        int stops = -1;
        while (!q.empty()) {
            int length = q.size();
            if (stops >= k)
                break;
            while (length--) {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int currCost = it.second;
                for (auto [adjNode, cost] : adj[node]) {
                    int costToTravelledAdjNode = currCost + cost;
                    if (costToTravelledAdjNode < dist[adjNode]) {
                        dist[adjNode] = costToTravelledAdjNode;
                        q.push({adjNode, costToTravelledAdjNode});
                    }
                }
            }
            stops++;
        }

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};