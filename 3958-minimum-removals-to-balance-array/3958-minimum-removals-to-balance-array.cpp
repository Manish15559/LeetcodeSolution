class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=(n-1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            long long val=(long long)k*nums[i];
            int idx=upper_bound(nums.begin(),nums.end(),val)-nums.begin();
            idx--;
            int removeCnt = n - (idx-i+1);
            ans=min(ans,removeCnt);
        }
        return ans;
        
    }
};