class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        int n=nums.size();

       vector<vector<int>>dp(n,vector<int>(k,0));

       
        for(int i=0;i<n;i++){
            dp[i][nums[i]%k]=1;
            for(int j=0;j<k;j++) dp[i][((j%k)*(nums[i]%k))%k]+=(i==0)?0:dp[i-1][j];
        }
        vector<long long>ans(k,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++) ans[j]+=dp[i][j];
        }

        return ans;
        
    }
};