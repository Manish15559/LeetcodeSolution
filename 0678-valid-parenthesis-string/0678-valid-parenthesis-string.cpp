class Solution {
public:
    bool helper(int idx,int count,string &s,vector<vector<int>>&dp){
        if(count<0) return 0;
        
        if(idx<0){
            if(count==0) return true;
            else return false;
        }
        if(dp[idx][count]!=-1) return dp[idx][count];
        if(s[idx]==')') return dp[idx][count]=helper(idx-1,(count+1),s,dp);
        else if(s[idx]=='(') return dp[idx][count]=helper(idx-1,(count-1),s,dp);
        else return dp[idx][count]=(helper(idx-1,count-1,s,dp)||helper(idx-1,count,s,dp)||helper(idx-1,count+1,s,dp));
     }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(n-1,0,s,dp);



        
    }
};