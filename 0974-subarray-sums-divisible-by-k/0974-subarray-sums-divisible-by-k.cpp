class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        cnt[0]=1;
        int ans=0;
        int sum=0;
        for(auto it:nums){
            sum+=it;
            // if(it==k) ans++;
            ans+=cnt[(sum%k)];
            if(sum>0){
                
                ans+=cnt[((sum%k)-k)];
            }
            else{
                 ans+=cnt[((sum%k)+k)];
            }
            cnt[sum%k]++;
            
        }
        return ans;
        
    }
};