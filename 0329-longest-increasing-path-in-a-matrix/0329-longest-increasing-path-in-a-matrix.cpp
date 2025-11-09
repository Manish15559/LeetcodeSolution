class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&matrix){
    int n=vis.size();
    int m=vis[0].size();

    int dis=0;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    for(int idx=0;idx<4;idx++){
        int nrow=row+dx[idx];
        int ncol=col+dy[idx];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&(matrix[row][col]<matrix[nrow][ncol])){
            if(!vis[nrow][ncol]) dfs(nrow,ncol,vis,matrix);
            dis=max(dis,vis[nrow][ncol]);
        }
    }

    vis[row][col]=1+dis;

    return;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        vector<array<int,3>>arr;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back({matrix[i][j],i,j});
            }
        }

        sort(arr.begin(),arr.end());
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(auto it:arr){
            int row=it[1];
            int col=it[2];
            if(!vis[row][col]){
                dfs(row,col,vis,matrix);
            }
            ans=max(ans,vis[row][col]);
        }
        return ans;
        
    }
};