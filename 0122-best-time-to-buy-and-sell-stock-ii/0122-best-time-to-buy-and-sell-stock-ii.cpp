class Solution {
public:
    int helper(int idx,bool isSelling,vector<int>&prices,vector<vector<int>>&dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][isSelling]!=-1) return dp[idx][isSelling];
        int noAction=helper(idx+1,isSelling,prices,dp);
        int action;
        if(isSelling){
            action=helper(idx+1,false,prices,dp)+prices[idx];

        }
        else{
            action=helper(idx+1,true,prices,dp)-prices[idx];
        }

        return dp[idx][isSelling]=max(action,noAction);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,false,prices,dp);
        
    }
};