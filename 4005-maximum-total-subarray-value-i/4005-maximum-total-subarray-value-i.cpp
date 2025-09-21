class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int mini=1e9+10;
        int maxi=-1;
        for(auto it:nums){
            mini=min(it,mini);
            maxi=max(it,maxi);
        }

        long long ans =(k*1ll*(maxi-mini));

        return ans;
        
    }
};