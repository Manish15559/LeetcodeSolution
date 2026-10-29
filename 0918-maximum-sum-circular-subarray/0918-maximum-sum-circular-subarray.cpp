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
            maxSum=max((maxSum+nums[i]),nums[i]);
            ans=max(ans,maxSum);
            minSum=min((minSum+nums[i]),nums[i]);
            mini=min(minSum,mini);
        }
        if(mini==totSum) return ans;
        ans=max(ans,(totSum-mini));
        return ans;
    }
};