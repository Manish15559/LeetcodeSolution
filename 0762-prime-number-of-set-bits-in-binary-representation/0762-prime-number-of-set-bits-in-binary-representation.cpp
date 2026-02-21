class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {

       unordered_set<int>prime;
       for(int i=2;i<30;i++){
        if(isPrime(i)) prime.insert(i);
       }

        int ans=0;
        while(left<=right){
            int cnt=0;
            for(int i=30;i>=0;i--){
                if((left>>i)&1) cnt++;
            }
           if(prime.find(cnt)!=prime.end()) ans++;
            left++;
        }
        return ans;
        
    }
};