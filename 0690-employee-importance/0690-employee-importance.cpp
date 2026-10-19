/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int helper(int node, vector<int> adj[], vector<int>& importance) {
        int tot = importance[node];

        for (auto it : adj[node]) {
            tot += helper(it, adj, importance);
        }
        return tot;
    }
    int getImportance(vector<Employee*> employees, int id) {
        vector<int> importance(2001,0);
        int n = 2001;
        vector<int> adj[n];
        // int n=employees.size();
        for (auto it : employees) {
            importance[it->id] = it->importance;
            for (auto subordinate : it->subordinates) {
                adj[it->id].push_back(subordinate);
            }
        }

        return helper(id, adj, importance);
    }
};