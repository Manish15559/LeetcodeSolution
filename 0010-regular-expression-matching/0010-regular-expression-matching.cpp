class Solution {
public:
    bool helper(int idx1, int idx2, string& s, string& p, vector<vector<int>>&dp) {
        if (idx2 == p.size())
            return (idx1 == s.size());
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        bool isMatch =
            (idx1 < s.size()) && (s[idx1] == p[idx2] || p[idx2] == '.');
        bool result;
        if ((idx2 + 1) < p.size() && p[idx2 + 1] == '*') {
            result = helper(idx1, idx2 + 2, s, p, dp) ||
                     (isMatch && helper(idx1 + 1, idx2, s, p, dp));
        } else {
            result = (isMatch && helper(idx1 + 1, idx2 + 1, s, p, dp));
        }

        return dp[idx1][idx2]=result;
    }
    bool isMatch(string s, string p) { 
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m,-1)); 
        return helper(0, 0, s, p, dp); 
        }
};