class Solution {
public:
    bool withInMatrix(int currRow,int currCol,int leftBoundary,int rightBoundary,int topBoundary,int downBoundary){
        if(currRow>=topBoundary&&currRow<=downBoundary&&currCol>=leftBoundary&&currCol<=rightBoundary) return true;
        else return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int dx[]={0,+1,0,-1};
        int dy[]={1,0,-1,0};
        int n=matrix.size();
        int m=matrix[0].size();
        int leftBoundary=0, rightBoundary=m-1,topBoundary=0,downBoundary=n-1;
        int idx=0;
        int count=0;
        vector<int>ans;
        int row=0;
        int col=0;

        while(count!=(n*m)){
            ans.push_back(matrix[row][col]);
            count++;
            int nrow=row+dx[idx];
            int ncol=col+dy[idx];
            if(withInMatrix(nrow,ncol,leftBoundary,rightBoundary,topBoundary,downBoundary)){
                row=nrow;
                col=ncol;
            }
            else{
                if(idx==0) topBoundary++;
                else if(idx==1) rightBoundary--;
                else if(idx==2) downBoundary--;
                else leftBoundary++;
                idx=(idx+1)%4;
                row+=dx[idx];
                col+=dy[idx];
            }

        }
        return ans;

        
    }
};