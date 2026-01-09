class Solution {
public:
    int dfs(int node,int parent,vector<int>adj[],unordered_set<int>&avoid){
        int tot=0;
        for(auto it:adj[node]){
            if(parent!=it&&avoid.find(it)==avoid.end()) tot+=dfs(it,node,adj,avoid);
        }
        return (1+tot);
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>avoid;
        for(auto node:restricted) avoid.insert(node);
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0,-1,adj,avoid);
    }
};