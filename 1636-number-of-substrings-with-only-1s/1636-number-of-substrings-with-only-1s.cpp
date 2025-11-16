class Solution {
public:
    int numSub(string s) {
        long long cnt=0;
        long long ans=0;
        for(auto it:s){
            if(it=='1') cnt++;
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        int m=1e9+7;
        ans%=m;
        return ans;
        
    }
};