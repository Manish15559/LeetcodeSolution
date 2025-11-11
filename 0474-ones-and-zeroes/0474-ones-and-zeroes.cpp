class Solution {
public:
int helper(int idx,int n,int m,vector<pair<int,int>>&arr,vector<vector<vector<int>>>&dp){
    if(idx==0){
        return ((arr[0].first<=n)&&(arr[0].second<=m));
    }
    if(dp[idx][n][m]!=-1) return dp[idx][n][m];
    int op1=0;
    if(arr[idx].first<=n&&arr[idx].second<=m) op1=1+ helper(idx-1,(n-arr[idx].first),(m-arr[idx].second),arr,dp);
    int op2= helper(idx-1,n,m,arr,dp);

    return dp[idx][n][m] = max(op1,op2);

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz =strs.size();
        vector<pair<int,int>>pre;
        vector<vector<vector<int>>>dp((sz),vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        for(int i=0;i<sz;i++){
            int zero=0;
            int one=0;
            for(auto it:strs[i]){
                if(it=='1') one++;
                else zero++;
            }
            pre.push_back({one,zero});
        }

        return helper(sz-1,n,m,pre,dp);
        
    }
};