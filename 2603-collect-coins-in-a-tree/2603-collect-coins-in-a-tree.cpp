class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1&&coins[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            indegree[node]=0;
            for(auto it:adj[node]){
                if(indegree[it]==0) continue;
                indegree[it]--;
                if(indegree[it]==1&&coins[it]==0) q.push(it);
            }
        }

        int k=2;
        while(k--){
            queue<int>leaf;
            for(int i=0;i<n;i++){
                if(indegree[i]==1) leaf.push(i);
            }

            while(!leaf.empty()){
                int node=leaf.front();
                leaf.pop();
                indegree[node]=0;
                for(auto it:adj[node]) {
                    if(indegree[it]>0) indegree[it]--;
            }
            }
        }

        int ans=0;
        for(auto it:indegree) ans+=it;

        return ans;
        
    }
};