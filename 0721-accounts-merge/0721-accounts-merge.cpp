class Solution {
public:
    void dfs(string& node, vector<string> &curr,
             unordered_map<string, vector<string>>& edges,
             unordered_set<string>& visited) {
        if (visited.find(node) != visited.end())
            return;
        curr.push_back(node);
        visited.insert(node);
        for (auto edge : edges[node]) {
            dfs(edge, curr, edges, visited);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> edges;
        for (auto account : accounts) {
            for (int idx = 2; idx < account.size(); idx++) {
                edges[account[idx]].push_back(account[idx - 1]);
                edges[account[idx - 1]].push_back(account[idx]);
            }
        }
        unordered_set<string> visited;
        vector<vector<string>> ans;
        for (auto account : accounts) {
            if (visited.find(account[1]) != visited.end())
                continue;
            vector<string> curr;
             curr.push_back(account[0]);
            dfs(account[1], curr, edges, visited);
            sort(curr.begin() + 1, curr.end());
            ans.push_back(curr);
        }
        return ans;
    }
};