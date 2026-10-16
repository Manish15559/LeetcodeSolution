class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> maxProb(n, 0);
        maxProb[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            double prob = it.first;
            if(prob<maxProb[node]) continue;
            for (auto it : adj[node]) {

                double value = it.second * maxProb[node];
                if (value > maxProb[it.first]) {
                    maxProb[it.first] = value;
                    pq.push({value, it.first});
                }
            }
        }
        return maxProb[end_node];
    }
};