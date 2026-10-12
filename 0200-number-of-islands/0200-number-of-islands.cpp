class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
        int dx[]={-1,1,0,0};  //LRUD
        int dy[]={0,0,1,-1};
        for(int idx=0;idx<4;idx++){
            int nrow=row+dx[idx];
            int ncol=col+dy[idx];
            if(nrow>=0&&ncol>=0&&nrow<grid.size()&&ncol<grid[0].size()){
                if(!vis[nrow][ncol]&&grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    dfs(nrow,ncol,grid,vis);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    count++;
                    vis[i][j]=1;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
        
    }
};