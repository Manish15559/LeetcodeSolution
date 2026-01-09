class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
        vis[row][col]=1;
       
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        int tot=0;
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0&&nrow<vis.size()&&ncol>=0&&ncol<vis[0].size()){
                if(!vis[nrow][ncol]&&grid[nrow][ncol]){
                   
                    tot+=dfs(nrow,ncol,vis,grid);
                    
                }
            }
        }
        return (tot+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0)); //sc : o(n*m)+o(n*m)
        int ans=0;

        for(int i=0;i<n;i++){  //tc : o(n*m)+o(4*n*m)
            for(int j=0;j<m;j++){ 
                if(!vis[i][j]&&grid[i][j]){
                    int curr=dfs(i,j,vis,grid);
                    ans=max(ans,curr);
                }

            }
        }

        return ans;
        
    }
};