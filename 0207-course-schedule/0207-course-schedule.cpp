class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<int> edge[numCourses];
        vector<int> indegree(numCourses, 0);
        for (auto it : prerequisites) {
            int node1 = it[0];
            int node2 = it[1];
            edge[node1].push_back(node2);
            indegree[node2]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {

            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : edge[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return ans.size() == numCourses;
    }
};