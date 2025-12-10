class Solution {
public:
    int specialTriplets(vector<int>& nums) {
       unordered_map<int,int>front,back;
       for(auto it:nums) back[it]++;

       int ans=0;
       int mod=1e9+7;
       for(int i=0;i<nums.size();i++){
        back[nums[i]]--;
        long long curr=front[(2*nums[i])]*(long long)1*back[(2*nums[i])];
        curr%=mod;
        ans+=curr;
        ans%=mod;
        front[nums[i]]++;
       }

       return ans;
        
    }
};