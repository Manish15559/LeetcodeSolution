class Solution {
public:
  long long binexp(long long a,long long b, int mod){
       if(b==0) return 1;
       long long val=binexp(a,b/2,mod);
       if(b%2==1) return (val*val*a)%mod;
       else return (val*val)%mod;
  }

    int countGoodNumbers(long long n) {
        int mod=1e9+7;
        long long primeNumber = binexp(4,n/2,mod);
        long long evenNumber =binexp(5,(n+1)/2,mod);

        return (primeNumber*evenNumber)%mod;
        
    }
};