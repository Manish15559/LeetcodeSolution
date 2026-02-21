class Solution {
public:
   int dfs1(int node,int parent,vector<pair<int,int>>adj[]){

    int tot=0;
    for(auto it:adj[node]){
        if(it.first==parent) continue;
        tot+=dfs1(it.first,node,adj);
        tot+=it.second;
    }
    return tot;
   }

   void dfs2(int node,int parent,vector<pair<int,int>>adj[],vector<int>&ans){

    for(auto it:adj[node]){
        if(it.first==parent) continue;
        if(it.second==0){
            ans[it.first]=ans[node]+1;
            dfs2(it.first,node,adj,ans);
        }
        else{
            ans[it.first]=ans[node]-1;
            dfs2(it.first,node,adj,ans);
        }
    }
   }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],0});
            adj[it[1]].push_back({it[0],1});
        }
        int cost = dfs1(0,-1,adj);
        vector<int>ans(n,0);
        ans[0]=cost;

        dfs2(0,-1,adj,ans);
        return ans;


        
    }
};