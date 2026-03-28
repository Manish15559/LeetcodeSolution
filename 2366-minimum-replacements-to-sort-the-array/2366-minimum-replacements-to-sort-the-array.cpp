class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[n-1];
        long long ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=prev) {
                prev=nums[i];
                continue;
            }
            else{
                int part=(nums[i]/prev)+((nums[i]%prev)!=0);
                ans+=(part-1);
                prev=nums[i]/part;
            }
        }

        return ans;
        
    }
};