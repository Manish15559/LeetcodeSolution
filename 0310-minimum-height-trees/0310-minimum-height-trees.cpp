class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         if(n==1) return {0};
        vector<int> indegree(n, 0);
        vector<int> adj[n];
        for (auto it : edges) {
            indegree[it[0]]++;
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        int count = n;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
                count--;
            }
        }
        while (count > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                indegree[node]--;

                for (auto it : adj[node]) {
                    if (indegree[it] > 0) {
                        indegree[it]--;

                        if (indegree[it] == 1) {
                            q.push(it);
                            count--;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};