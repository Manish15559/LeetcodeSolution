class Solution {
public:
   int dfs(int node,int parent,vector<int>adj[],vector<int>&values,int &count,int k){
    int tot=0;
    for(auto it:adj[node]){
        if(it==parent) continue;
        tot+=dfs(it,node,adj,values,count,k);
        tot%=k;
    }
    tot+=values[node];
    tot%=k;
    count+=(tot==0);

    return tot;
   }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<int>adj[n+1];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int root=0;
        for(int node=0;node<n;node++){
            if(adj[node].size()==1) {
                root=node;
                break;
            }
        }
        int count=0;
        dfs(root,-1,adj,values,count,k);

        return (count);

        
    }
};