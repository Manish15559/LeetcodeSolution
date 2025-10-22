class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans=0;
       int prev=-1e9;
       for(auto it:nums){
        int l=max((prev+1),(it-k));
        if(l<=(it+k)){
            prev=l;
            ans++;
        }
       }
       return ans;
        
    }
};