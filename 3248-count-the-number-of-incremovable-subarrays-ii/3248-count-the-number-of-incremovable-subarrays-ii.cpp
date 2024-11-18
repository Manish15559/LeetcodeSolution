class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int right=n-1;
        while(right>0&&nums[right]>nums[right-1]){
          
            right--;
        }
        if(right>0) ans++;
        ans+=(n-right); 
        for(int left=0;left<n;left++){
            if(left>0&&nums[left]<=nums[left-1]) break;

            while(right<n&&nums[right]<=nums[left]){
                right++;
            }
            if((right-left)>1){
                ans++;
            }
            ans+=(n-right);
        }
        return ans;
    }
};