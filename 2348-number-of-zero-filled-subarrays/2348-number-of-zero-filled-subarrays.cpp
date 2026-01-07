class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int cnt=0;
        long long ans=0;
        for(auto it:nums){
            if(it==0){
                cnt++;
                ans+=cnt;
            }
            else{
                cnt=0;
            }
        }

        return ans;
        
    }
};