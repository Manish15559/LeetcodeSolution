class Solution {
public:
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
   
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;

                }
            
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m= grid[0].size();

        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    vis[i][j]=1;
                   
                    bfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
        
    }
};