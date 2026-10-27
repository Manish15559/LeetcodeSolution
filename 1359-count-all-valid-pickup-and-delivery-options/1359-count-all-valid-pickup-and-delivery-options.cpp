class Solution {
public:
    int countOrders(int n) {
      
        long long ans=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            int p=(n-i+1);
            int c=(2*n-(2*i-1));
            long long val= (p*1ll*c)%mod;
            ans=((ans%mod)*(val%mod))%mod;

        }

        return ans;
        
    }
};