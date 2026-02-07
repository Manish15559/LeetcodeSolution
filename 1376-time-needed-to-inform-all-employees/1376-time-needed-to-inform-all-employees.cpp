class Solution {
public:
    int dfs(int node,vector<int>adj[],vector<int>&informTime){
        if(adj[node].size()==0) return 0;
        int time=0;
        for(auto it:adj[node]){
            time=max(time,dfs(it,adj,informTime));
        }

        return (time+informTime[node]);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        int totalTime=0;
       return  dfs(headID,adj,informTime);
        
    }
};