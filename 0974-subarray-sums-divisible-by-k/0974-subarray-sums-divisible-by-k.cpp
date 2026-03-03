class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        cnt[0]=1;
        int ans=0;
        int sum=0;
        for(auto it:nums){
            sum+=(it%k+k);
            sum%=k;
            // if(it==k) ans++;
            ans+=cnt[sum];
           
            cnt[sum]++;
            
        }
        return ans;
        
    }
};