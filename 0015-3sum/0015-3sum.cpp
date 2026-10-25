class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int idx=0;idx<n;idx++){
            if(idx>0&&nums[idx]==nums[idx-1]) continue;
            int left=idx+1;
            int right=n-1;
            while(left<right){
                if((left)>(idx+1)&&nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
                if((right<(n-1)&&nums[right]==nums[right+1])) {
                    right--;
                    continue;
                }
                int sum=(nums[idx]+nums[left]+nums[right]);
                if(sum==0) {
                    ans.push_back({nums[idx],nums[left],nums[right]}); 
                    left++;
                    right--;
                }
                else if (sum<0) left++;
                else right--;
            }
        }
        return ans;
        
    }
};