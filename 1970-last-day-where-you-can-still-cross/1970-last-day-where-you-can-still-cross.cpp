class Solution {
public:
    bool check(int day,int n,int m,vector<vector<int>>& cells){
        if(n==1) return true;
        vector<vector<int>>matrix(n,vector<int>(m,0));

        for(int idx=0;idx<day;idx++){
            matrix[cells[idx][0]-1][cells[idx][1]-1]=1;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(!matrix[0][i]){
                q.push({0,i});
                matrix[0][i]=1;
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int idx=0;idx<4;idx++){
                int nrow=row+dx[idx];
                int ncol=col+dy[idx];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&!matrix[nrow][ncol]){
                    if(nrow==(n-1)) return true;
                    q.push({nrow,ncol});
                    matrix[nrow][ncol]=1;
                }
            }

        }
        return false;

    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int low=0;
        int high=cells.size();
        while(high-low>1){
            int mid=(high+low)/2;

            if(check(mid,row,col,cells)) low=mid;
            else high=mid-1;
        }

        if(check(high,row,col,cells)) return high;
        else return low;
        
    }
};