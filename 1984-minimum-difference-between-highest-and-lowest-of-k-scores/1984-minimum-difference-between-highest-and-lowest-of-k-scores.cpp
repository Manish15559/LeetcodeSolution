class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1e9;
        for(int i=k-1;i<nums.size();i++){
            int val=nums[i]-nums[(i-k+1)];
            ans=min(ans,val);
        }
        return ans;
        
    }
};