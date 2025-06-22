class Solution {
public:
    long long dfs(int node,int parent,vector<int>adj[],vector<int>&cost,int &count){
        long long mx=0;
        int cnt=0;
        int totcnt=0;
        for(auto it:adj[node]){
            if(it!=parent){
                totcnt++;
                long long val=dfs(it,node,adj,cost,count);
                if(mx<val){
                    mx=val;
                    cnt=1;

                }
                else if(mx==val) cnt++;
                
            }
        }
        count+=(totcnt-cnt);
        return (cost[node]+mx);
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {

        vector<int>adj[n];

        for(auto it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;

        dfs(0,-1,adj,cost,count);

        return count;
        
    }
};