class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>count(51,0);
        for(auto it:nums) count[it]++;
       
        if(n<k) return -1;
      
      if(k==1){
        int mx=-1;
        for(auto it:nums) if(count[it]==1) mx=max(mx,it);
        return mx;

      }
      if(k==n){
        int mx=-1;
        for(auto it:nums)  mx=max(mx,it);
        return mx;

      }

        if(count[nums[0]]==1&&count[nums[n-1]]==1){
            return max(nums[0],nums[n-1]);
        }
        else if(count[nums[0]]==1) return nums[0];
        else if(count[nums[n-1]]==1) return nums[n-1];
        else return -1;
        
    }
};