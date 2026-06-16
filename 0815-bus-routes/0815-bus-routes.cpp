class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        int N = 1e6 + 10;
        if (source == target)
            return 0;
        vector<int> dist(N, -1);
        dist[source] = 0;
        queue<int> q;
        vector<unordered_set<int>> list;
        int n=routes.size();
        vector<int>visited(n,0);
        for (auto &it : routes) {
            unordered_set<int> st;
            for (auto iter : it) {
                st.insert(iter);
            }
            list.push_back(st);
        }
        q.push(source);
        while (!q.empty()) {

            int node = q.front();
            // cout<<node<<" "<<dist[node]<<endl;
            q.pop();

            for (int i=0;i<n;i++) {
                if(visited[i]==1) continue;
                if (list[i].find(node) != list[i].end()) {
                    visited[i]=1;
                    for (auto nextNode : list[i]) {

                        if (dist[nextNode] != -1)
                            continue;
                        if (nextNode == target)
                            return (dist[node] + 1);
                        dist[nextNode] = dist[node]+1;
                        q.push(nextNode);
                    }
                }
            }
        }

        return -1;
    }
};