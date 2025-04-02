class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        int mini=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=3;i++){
            int diff=nums[n-4+i]-nums[i];
            mini=min(mini,diff);
            

        }
        return mini;
        
    }
};