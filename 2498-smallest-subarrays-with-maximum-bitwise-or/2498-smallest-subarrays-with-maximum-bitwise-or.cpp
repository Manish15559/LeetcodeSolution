class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans(n,-1);
        vector<int>pos(31,-1);
        for(int i=n-1;i>=0;i--){
            int mx=i;
            for(int bit=0;bit<31;bit++){
                if((nums[i]>>bit)&1){
                    pos[bit]=i;
                }
                else{
                    if(pos[bit]!=-1) mx=max(mx,pos[bit]);
                }
            
            }
            ans[i]=(mx-i+1);
        
        }
        return ans;
        
    }
};