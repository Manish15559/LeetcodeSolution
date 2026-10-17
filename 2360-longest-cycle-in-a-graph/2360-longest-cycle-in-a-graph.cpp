class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> depth(n, 0);
        vector<int> visitedId(n, -1);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (visitedId[i] != -1)
                continue;

            int node = i;
            int path = 0;
            while (node!=-1 && visitedId[node] == -1) {
                visitedId[node] = i;
                depth[node] = path;
                path++;
                node = edges[node];
            }
            if (node !=-1 && visitedId[node] == i) {
                ans = max(ans, (path - depth[node]));
            }
        }
        return ans;
    }
};