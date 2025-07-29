class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        int mx=0;
        int n=nums.size();
        for(int bit=0;bit<(1<<n);bit++){
            int curr=0;
            for(int i=0;i<n;i++){
                if((bit>>i)&1) curr|=nums[i];
            }
            if(curr==mx) ans++;
            else if(curr>mx){
                mx=curr;
                ans=1;
            }
           
        }

        return ans;
    }
};