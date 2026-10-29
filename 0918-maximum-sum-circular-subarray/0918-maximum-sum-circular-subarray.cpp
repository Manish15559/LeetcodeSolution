class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n=nums.size();
        int totSum=0;

        int maxSum=0;
        int ans=-1e9;
        int minSum=0;
        int mini=1e9;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
            maxSum+=nums[i];
            ans=max(ans,maxSum);
            if(maxSum<0) maxSum=0;
            minSum+=nums[i];
            mini=min(minSum,mini);
            if(minSum>0) minSum=0;
        }
        if(mini==totSum) return ans;
        ans=max(ans,(totSum-mini));
        return ans;
    }
};