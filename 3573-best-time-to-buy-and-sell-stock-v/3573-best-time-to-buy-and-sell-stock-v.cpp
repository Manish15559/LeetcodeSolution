const int N=1e3+10;
long long dp[N][N/2][3];

class Solution {
public: 

    long long helper(int idx,int type,int k,vector<int>&prices){
        if(idx==prices.size()) {
            if(type==0) return 0;
            else return (-1e15);
        }
        if(dp[idx][k][type]!=-1) return dp[idx][k][type];

        //type=0 //nothing
        if(type==0){
            //skip
            long long op1=helper(idx+1,type,k,prices);

            //buy
            long long op2=0;
            //sell
            long long op3=0;
            if(k>0){
                op2=helper(idx+1,1,(k-1),prices)-prices[idx];
                op3=helper(idx+1,2,(k-1),prices)+prices[idx];

            }

            return dp[idx][k][type]=max({op1,op2,op3});
        }
        else if(type==1){
            //skip
         long long op1=helper(idx+1,type,k,prices);

         //sell
         long long op2=helper(idx+1,0,k,prices)+prices[idx];

         return dp[idx][k][type]=max(op1,op2);

        }

        else{
             //skip
         long long op1=helper(idx+1,type,k,prices);

         //buy
         long long op2=helper(idx+1,0,k,prices)-prices[idx];

         return dp[idx][k][type]=max(op1,op2);


        }

        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));

       

        return helper(0,0,k,prices);
        
    }
};