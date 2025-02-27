class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        int mx=0;
        int mi=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max({abs(sum-mi),abs(sum-mx),ans});
            mx=max(mx,sum);
            mi=min(mi,sum);
        }

        return ans;
        
    }
};