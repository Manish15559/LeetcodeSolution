class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0;
        int curr=0;
        int ans=0;
        bool haveNeg=false;
        for(auto it:nums){
            if(it==0){
                prev=curr;
                curr=0;
                haveNeg=true;
            }
            else{
                curr++;
                ans=max(ans,(curr+prev));
            }
        }
        ans-=(haveNeg==false);

        return ans;
        
    }
};