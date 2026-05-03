class Solution {
public:
    bool isBipartite(int node, int col, vector<int>& color, vector<int> adj[]) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (isBipartite(it, (!col), color, adj) == false)
                    return false;
            } else if (color[it] == color[node])
                return false;
        }
        return true;
    }
    int findFarestNode(int node, int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto adjNode = q.front();
                q.pop();
                for(auto it:adj[adjNode]){
                if (vis[it] == 0) {
                    vis[it] = 1;
                    q.push(it);
                }
                }
            }
        }
        return cnt;
    }
    int maxDistBetweenNode(int node, vector<int>& vis, vector<int>& dist,
                           vector<int> adj[]) {
        int curr = dist[node];
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it] == 0)
                curr = max(curr, maxDistBetweenNode(it, vis, dist, adj));
        }
        return curr;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);
        for (int node = 0; node < n; node++) {
            if (color[node] == -1) {
                if (isBipartite(node, 0, color, adj) == false)
                    return -1;
            }
        }

        vector<int> dist(n, 0);

        for (int node = 0; node < n; node++) {
            dist[node] = findFarestNode(node, n, adj);
        }
        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int curr = maxDistBetweenNode(i, vis, dist, adj);
                ans += curr;
            }
        }
        return ans;
    }
};