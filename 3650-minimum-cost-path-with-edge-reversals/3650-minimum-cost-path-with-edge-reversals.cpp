class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {


        vector<pair<int,int>>adj[n];

        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],(2*edge[2])});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int distance=it.first;
            pq.pop();
            if(distance>dist[node]) continue;
           
            for(auto it:adj[node]){
                if((distance+it.second)<dist[it.first]){
                    dist[it.first]=distance+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
       if(dist[n-1]==1e9) return -1;
        return dist[n-1];
        
    }
};