class Solution {
public:
    void findCycle(int node,int pathLen, int &ans,vector<int>&vis,vector<int>&pathVis,vector<int>&edges){
        vis[node]=1;
        int adjNode=edges[node];
        if(adjNode==-1) return;
        pathVis[node]=pathLen+1;
        
        
        if(!vis[adjNode]){
            findCycle(adjNode,(pathLen+1),ans,vis,pathVis,edges);
        }
        else if(pathVis[adjNode]!=0){
            ans=max(ans,(pathLen-pathVis[adjNode]+2));

        }
        pathVis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        int ans=-1;

        for(int node=0;node<n;node++){
            if(!vis[node]) findCycle(node,0,ans,vis,pathVis,edges);
        }
        
        return ans;
        
    }
};