class Solution {
public:
    int helper(int target, vector<int>& nums,vector<int>& dp) {
       if(target==0) return 1;
       if(dp[target]!=-1) return dp[target];

       int op=0;
       for(auto it:nums){
        if(it<=target) op+=helper(target-it,nums,dp);
       }
       return dp[target]=op;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return helper(target, nums, dp);
    }
};