class Solution {
public:
   int helper(int idx,int prev,vector<int>&nums,vector<vector<int>>&dp){

    if(idx==nums.size()) return 0;

    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];


    // take
    int taken = 0;
    if(prev==-1||nums[idx]>nums[prev]) taken =1+helper(idx+1,idx,nums,dp);
    //not take it
    int nottaken=helper(idx+1,prev,nums,dp);

    return dp[idx][prev+1]=max(taken,nottaken);
   }
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
       vector<int>dp(n,1);

       for(int idx=0;idx<n;idx++){
        for(int j=idx-1;j>=0;j--){
            if(nums[j]<nums[idx]) dp[idx]=max((1+dp[j]),dp[idx]);

        }
       }
       int ans=0;
       for(auto it:dp) ans=max(ans,it);

       return ans;



      
        
    }
};