class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[102][102]={0.0};
        dp[0][0]=(double)poured;
        bool empty=false;
        for(int row=0;row<=query_row;row++){
            if(empty) break;
            for(int col=0;col<=row;col++){
                if(dp[row][col]>1.0){
                    double extra = (dp[row][col]-1.0)/2.0;
                    dp[row][col]=1.0;
                    dp[row+1][col]+=extra;
                    dp[row+1][col+1]+=extra;
                }
                
            }

        }

        return dp[query_row][query_glass];
        
    }
};