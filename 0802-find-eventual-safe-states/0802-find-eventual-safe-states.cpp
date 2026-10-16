class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis,vector<int>&safeNode){

        vis[node]=1;
        pathVis[node]=1;
        for(auto adjNode:graph[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,graph,vis,pathVis,safeNode)){
                    safeNode[node]=0;
                    return true;
                }
            }
            else if(pathVis[adjNode]==1){
                safeNode[node]=0;
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),pathVis(n,0),safeNode(n,1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,safeNode);
            }
        }
        vector<int>ans;
        for(int node=0;node<n;node++) {
            if(safeNode[node]==1) ans.push_back(node);
        }
        return ans;
        
    }
};