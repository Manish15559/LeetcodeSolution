class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>dp1(n+1,0);
        vector<int>dp2(n+1,0);
        for(int i=1;i<=n;i++){
            dp1[i]=dp1[i-1]+(s[i-1]=='a'?1:0);
            dp2[i]=dp2[i-1]+(s[i-1]=='b'?1:0);
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            int x=dp1[i];
            int y=dp2[n]-dp2[i];
            ans=min(ans,n-x-y);
        }
        return ans;
        
    }
};