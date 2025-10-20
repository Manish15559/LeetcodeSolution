class Solution {
public:
    bool isValid(int row,int col,int n){
        return (row>=0&&col>=0&&row<n&&col<n);

    }
    bool check(int safe,vector<vector<int>>&arr,int n){
        queue<pair<int,int>>q;
        if(arr[0][0]<safe) return false;
        q.push({0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto coordinate=q.front();
            int row=coordinate.first;
            int col=coordinate.second;
            if(row==(n-1)&&row==col) return true;
            q.pop();
            for(int idx=0;idx<4;idx++){
                int nrow=row+dx[idx];
                int ncol=col+dy[idx];
                if(isValid(nrow,ncol,n)&&arr[nrow][ncol]>=safe&&!vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    
                    q.push({nrow,ncol});
                }
            }

        }
        return false;

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>arr(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    arr[i][j]=0;
                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto coordinate=q.front();
            int row=coordinate.first;
            int col=coordinate.second;
            q.pop();
            for(int idx=0;idx<4;idx++){
                int nrow=row+dx[idx];
                int ncol=col+dy[idx];
                if(isValid(nrow,ncol,n)&&arr[nrow][ncol]==-1){
                    arr[nrow][ncol]=arr[row][col]+1;
                    q.push({nrow,ncol});
                }
            }

        }
       
        int low=0;
        int high=2*n-2;
        while(high-low>1){
            int mid=(low+high)/2;
            if(check(mid,arr,n)) low=mid;
            else high=mid-1;
        }
        if(check(high,arr,n)) return high;
        else return low;
        
    }
};