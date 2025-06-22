class Solution {
public:
    int f(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(idx==0){
            if(amount%coins[idx]) return 0;
            else return 1;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        // take
        int op1=0;
        if(amount>=coins[idx]){
            op1=f(idx,amount-coins[idx],coins,dp);
        }
        int op2=f(idx-1,amount,coins,dp);
        return dp[idx][amount]=op1+op2;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
        
    }
};