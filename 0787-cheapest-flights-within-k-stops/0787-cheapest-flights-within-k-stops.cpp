class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+1,1e9));
        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src][0] = 0;
        int stops = 0;
        while (!q.empty()) {
            int length = q.size();
            if (stops > k)
                break;
            while (length--) {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int currCost = it.second;
                for (auto [adjNode, cost] : adj[node]) {
                    int costToTravelledAdjNode = currCost + cost;
                    if (costToTravelledAdjNode < dist[adjNode][stops]) {
                        dist[adjNode][stops] = costToTravelledAdjNode;
                        q.push({adjNode, costToTravelledAdjNode});
                    }
                }
            }
            stops++;
        }
        int ans=1e9;
        for(auto it:dist[dst]) ans=min(ans,it);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};