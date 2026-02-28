class Solution {
public:
    
    int concatenatedBinary(int n) {

        int mod = 1e9 + 7;
        int rem = 0;
        int mx = 0;
        for (int num = 1; num <= n; num++) {
            int rightMostBit=0;
            for(int i=0;i<30;i++){
                if((num>>i)&1) rightMostBit=i;
            }
          

            for (int i=rightMostBit;i>=0;i--) {
                rem = (2 * rem) % mod;
                if ((num>>i&1) == 1)
                    rem++;
                rem %= mod;
            }
        }

        return rem;
    }
};