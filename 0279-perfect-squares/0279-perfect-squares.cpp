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
       
      vector<int>dp(n+1,INT_MAX);
      dp[0]=0;
      int count=1;
      while(count*count<=n){
        int sq=count*count;
        for(int i=sq;i<n+1;i++){
            dp[i]=min(dp[i-sq]+1,dp[i]);
        }
        count++;
      }

      return dp[n];
    }
};