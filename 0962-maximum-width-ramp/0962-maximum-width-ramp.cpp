class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++) arr.push_back({nums[i],i});
        sort(arr.begin(),arr.end());

        int ans=0;
        int mini=arr[0].second;
        for(auto it:arr){
            ans=max(ans,(it.second-mini));
            mini=min(mini,it.second);
        }
        return ans;
        
    }
};