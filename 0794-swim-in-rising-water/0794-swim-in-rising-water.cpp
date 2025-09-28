class Solution {
public:

bool check(int t,vector<vector<int>>&grid){
    if(grid[0][0]>t) return false;
    int n=grid.size();
    vector<vector<int>>vis(n,vector<int>(n,0));

    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        for(int idx=0;idx<4;idx++){
            int nrow=row+dx[idx];
            int ncol=col+dy[idx];
            if(nrow>=0&&ncol>=0&&ncol<n&&nrow<n&&!vis[nrow][ncol]&&grid[nrow][ncol]<=t){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
                if(nrow==(n-1)&&ncol==(n-1)) return true;
            }
        }
    }
    return false;

}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return 0;

        int low=0;
        int high=(n*n)-1;
        while(high-low>1){
            int mid=(low+high)/2;
            if(check(mid,grid)==true) high=mid;
            else low=mid+1;
        }

        if(check(low,grid)) return low;
        else return high;

        
    }
};