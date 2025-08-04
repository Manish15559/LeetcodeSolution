class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=(n-1);
        sort(nums.begin(),nums.end());
       int left=0;
       for(int right=0;right<n;right++){
        if(nums[right]> (long)k*nums[left]) left++;
        ans=min(ans,(n-(right-left+1)));
       }
        return ans;
        
    }
};