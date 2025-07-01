class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;

        for(int i=0;i<=min(limit,n);i++){
            int left=n-i;
            if(left>2*limit) continue;
            else if(left>limit) ans+=(2*limit-left+1);
            else ans+=left+1;
        }
        return ans;
        
    }
};