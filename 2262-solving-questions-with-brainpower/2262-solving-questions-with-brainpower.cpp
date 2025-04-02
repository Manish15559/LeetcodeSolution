class Solution {
public:
long long helper(int idx,vector<vector<int>>& questions,vector<long long>&dp){
    if(idx>=questions.size()) return 0;

    if(dp[idx]!=-1) return dp[idx];
    //skip
    long long op1=helper(idx+1,questions,dp);
    long long op2=helper(idx+questions[idx][1]+1,questions,dp)+questions[idx][0];

    return dp[idx]=max(op1,op2);
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,0);

        for(int idx=n-1;idx>=0;idx--){
            long long op1=dp[idx+1];
            long long op2=dp[min(idx+questions[idx][1]+1,n)]+questions[idx][0];
            dp[idx]=max(op1,op2);


        }

        return dp[0];
        
    }
};