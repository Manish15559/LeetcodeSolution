class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefSum=1;
        int suffSum=1;
        int n=nums.size();
        int ans=nums[0];
        for(int i=0;i<n;i++){
            prefSum*=nums[i];
            suffSum*=nums[n-i-1];
            ans=max({ans,prefSum,suffSum});
            if(prefSum==0) prefSum=1;
            if(suffSum==0) suffSum=1;
        }
        return ans;
        
    }
};