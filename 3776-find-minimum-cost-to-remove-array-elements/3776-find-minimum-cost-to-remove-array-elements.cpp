class Solution {
public:
    int minCost(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<vector<int>>dp(n,vector<int>(n,1e9+10));

        dp[2][0]=max(nums[2],nums[1]);
        dp[2][1]=max(nums[0],nums[2]);
        dp[2][2]=max(nums[0],nums[1]);

        for(int i=4;i<n;i+=2){
            for(int j=0;j<=(i-2);j++){
                dp[i][j]=dp[i-2][j]+max(nums[i],nums[i-1]);
            }
            for(int j=0;j<=i-1;j++){
                dp[i][i-1]=min(dp[i][i-1],dp[i-2][j]+max(nums[j],nums[i]));
                dp[i][i]=min(dp[i][i],dp[i-2][j]+max(nums[j],nums[i-1]));

            }
        }
        if(n%2==1){
            int ans=1e9+10;
            for(int j=0;j<n;j++){
               ans=min(ans,dp[n-1][j]+nums[j]);
            }

            return ans;

        }
        else{
             int ans=1e9+10;
            for(int j=0;j<n;j++){
               ans=min(ans,dp[n-2][j]+max(nums[j],nums[n-1]));
            }

            return ans;

        }

        


        
    }
};