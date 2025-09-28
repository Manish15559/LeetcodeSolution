class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {


        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

        queue<array<int,3>>q;
        q.push({0,0,k});
        dp[0][0][k]=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        if(n==1&&m==1) return 0;

        while(!q.empty()){
            int row=q.front()[0];
            int col=q.front()[1];
            int curr_k=q.front()[2];
           
            q.pop();

            for(int idx=0;idx<4;idx++){
                int nrow=row+dx[idx];
                int ncol=col+dy[idx];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    //  cout<<nrow<<" "<<ncol<<" "<<dp[nrow][ncol][curr_k]<<endl;
                    if(grid[nrow][ncol]==0&&dp[nrow][ncol][curr_k]==-1){
                        if(nrow==(n-1)&&ncol==(m-1)) return (dp[row][col][curr_k]+1);
                        dp[nrow][ncol][curr_k]=1+dp[row][col][curr_k];
                        q.push({nrow,ncol,curr_k});
                    }
                    else if(grid[nrow][ncol]==1&&curr_k>0&&dp[nrow][ncol][(curr_k-1)]==-1){
                        if(nrow==(n-1)&&ncol==(m-1)) return (dp[row][col][curr_k]+1);
                        dp[nrow][ncol][(curr_k-1)]=1+dp[row][col][curr_k];
                        q.push({nrow,ncol,(curr_k-1)});

                    }

                }
            }
            

        }

        return -1;

        
    }
};