class Solution {
public:

bool isSafe(int row,int col,int n,vector<int>&rowVisited,vector<int>&rightDiagonal,vector<int>&leftDiagonal){
    if(rowVisited[row]==1||rightDiagonal[(n+row-col)]==1||leftDiagonal[(row+col)]==1) return false;

    return true;


}

    int helper(int col,int n,vector<int>&rowVisited,vector<int>&rightDiagonal,vector<int>&leftDiagonal){
        if(col==n) return 1;

        int tot=0;
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,rowVisited,rightDiagonal,leftDiagonal)){
                rowVisited[row]=1;
                rightDiagonal[(n+row-col)]=1;
                leftDiagonal[(row+col)]=1;
                tot+=helper(col+1,n,rowVisited,rightDiagonal,leftDiagonal);
                rowVisited[row]=0;
                rightDiagonal[(n+row-col)]=0;
                leftDiagonal[(row+col)]=0;


            }
        }
        return tot;
    }
    int totalNQueens(int n) {

        vector<int>rowVisited(n,0), rightDiagonal(2*n,0), leftDiagonal(2*n,0);

        return helper(0,n,rowVisited,rightDiagonal,leftDiagonal);


        
    }
};