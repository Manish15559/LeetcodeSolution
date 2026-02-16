class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit) ans = (ans|(1<<(31-i)));
        }
        return ans;
        
    }
};