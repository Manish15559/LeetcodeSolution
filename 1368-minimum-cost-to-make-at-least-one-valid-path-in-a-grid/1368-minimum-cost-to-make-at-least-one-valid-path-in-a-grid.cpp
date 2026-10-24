class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>costToReach(n,vector<int>(m,1e9));
        costToReach[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int cost=it[0];
            int row=it[1];
            int col=it[2];
            pq.pop();
            if(cost>costToReach[row][col]) continue;
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int idx=1;idx<=4;idx++){
                int nrow=row+dx[idx-1];
                int ncol=col+dy[idx-1];
                if(!isValid(nrow,ncol,n,m)) continue;
                int adjCost=cost+(idx!=grid[row][col]);
                if(adjCost<costToReach[nrow][ncol]){
                    pq.push({adjCost,nrow,ncol});
                    costToReach[nrow][ncol]=adjCost;
                }
            }

        }

        return costToReach[n-1][m-1];
        
    }
};