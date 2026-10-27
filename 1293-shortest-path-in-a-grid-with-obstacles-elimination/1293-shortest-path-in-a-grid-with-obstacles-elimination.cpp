class Solution {
public:
    class Compare{
        public:
        bool operator()(vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1]; //decreasing
            return a[0]>b[0]; //increasing
        }
    };
    bool isValid(int row,int col,int n,int m){
        return row>=0&&row<n&&col>=0&&col<m;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dist(n,vector<vector<int>>(m,vector<int>(k+1,1e9)));
        priority_queue<vector<int>,vector<vector<int>>,Compare>pq;
        dist[0][0][k]=0;
        pq.push({0,k,0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int row=it[2];
            int col=it[3];
            int distance=it[0];
            int left=it[1];
            if(dist[row][col][left]<distance) continue;
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int idx=0;idx<4;idx++){
                int nrow=row+dx[idx];
                int ncol=col+dy[idx];
                if(!isValid(nrow,ncol,n,m)) continue;
                int nLeft=left-(grid[nrow][ncol]==1);
                if(nLeft>=0&&(distance+1)<dist[nrow][ncol][nLeft]){
                    pq.push({(distance+1),nLeft,nrow,ncol});
                    dist[nrow][ncol][nLeft]=distance+1;
                }
            }
        }
        int ans=1e9;
        for(auto it:dist[n-1][m-1]){
            ans=min(it,ans);
        }
        if(ans==1e9) return -1;

        return ans;
        
    }
};