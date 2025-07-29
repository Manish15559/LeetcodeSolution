class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        long long ans=0;
        while(left<right){
            ans+=nums[right-1];
            left++;
            right-=2;
        }
        return ans;
        
    }
};