class Solution {
public:
    bool check(int source, int target, vector<pair<int, int>> adj[],
               int threshold, int k, int n) {
        deque<pair<int,int>>q;
        vector<int> dist(n, (k + 1));
        dist[source] = 0;
        q.push_front({source, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop_front();
            int node = it.first;
            int wt = it.second;
            if (wt > dist[node])
                continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int weight = wt + (it.second > threshold);
                if (weight < dist[adjNode]) {
                    dist[adjNode] = weight;
                    if(it.second>threshold)
                    q.push_back({adjNode, weight});
                    else
                    q.push_front({adjNode,weight});
                }
            }
        }

        return dist[target] <= k;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
                         int target, int k) {
        int maxEdge = 0;
        vector<pair<int, int>> adj[n];
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            maxEdge = max(wt, maxEdge);
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        if (check(source, target, adj, maxEdge, k, n) == false)
            return -1;

        int low = 0;
        int high = maxEdge;
        while ((high - low) > 1) {
            int mid = (low + high) / 2;
            if (check(source, target, adj, mid, k, n))
                high = mid;
            else
                low = mid + 1;
        }
        if (check(source, target, adj, low, k, n))
            return low;
        return high;
    }
};