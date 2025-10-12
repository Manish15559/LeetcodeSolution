class Solution {
public:
int helper(int n,int idx,vector<int>&arr,vector<vector<int>>&dp){
    if(n==0) return 0;
    if(idx<0) return 1e9;
    if(dp[idx][n]!=-1) return dp[idx][n];
    int best=1e9;
    if(n>=arr[idx]){
        best= 1+helper((n-arr[idx]),idx,arr,dp);
    }
    best=min(best,helper(n,idx-1,arr,dp));
    return dp[idx][n]=best;
}
    int numSquares(int n) {
       
        int i=1;
        vector<int>prefectSquares;
        while((i*i)<=n){
            prefectSquares.push_back(i*i);
            i++;
        }
        int m=prefectSquares.size();
        vector<vector<int>>dp(m,vector<int>(n+1,0));

        for(int idx=0;idx<m;idx++){
            for(int val=1;val<=n;val++){
                int ans=1e9;
                if(val>=prefectSquares[idx]) ans=1+dp[idx][val-prefectSquares[idx]];
                if(idx>0) ans=min(ans,dp[idx-1][val]);
                dp[idx][val]=ans;

            }
        }
        return dp[m-1][n];
        
    }
};