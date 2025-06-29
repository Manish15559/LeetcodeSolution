class Solution {
public:
long long binexp(int n,int mod){
    if(n==0) return 1;
    long long val=binexp(n/2,mod);
    if(n%2) return ((val%mod)*2*(val%mod))%mod;
    else return ((val%mod)*(val%mod))%mod;
}
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            // cout<<ans<<endl;
            if((2*nums[i])>target) break;
            ans++;
            int idx=upper_bound(nums.begin(),nums.end(),(target-nums[i]))-nums.begin();
            // cout<<idx<<endl;
            if(i>=idx) continue;
            long long cnt=idx-i-1;
            long long val=binexp(cnt,mod)-1;
            val%=mod;
            ans+=val;
            ans%=mod;
        }
        return ans;
        
    }
};