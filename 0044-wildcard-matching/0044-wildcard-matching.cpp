class Solution {
public:
    bool helper(int idx1, int idx2, string& s, string& p,
                vector<vector<int>>& dp) {
        if (idx2 == p.size())
            return idx1 == s.size();
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        bool isMatch = (idx1 < s.size()) &&
                       (s[idx1] == p[idx2] || p[idx2] == '?' || p[idx2] == '*');
        bool result;
        if (p[idx2] == '*') {
            result = helper(idx1, idx2 + 1, s, p, dp) ||
                     (isMatch && helper(idx1 + 1, idx2, s, p, dp));
        } else {
            result = isMatch && helper(idx1 + 1, idx2 + 1, s, p, dp);
        }
        return dp[idx1][idx2] = result;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>curr(m+1,0),prev(m+1,0);
        // prev[m] = 1;
        // curr[m]=1;
        for (int idx1 = n; idx1 >= 0; idx1--) {
             curr[m] = (idx1 == n);
            for (int idx2 = m - 1; idx2 >= 0; idx2--) {
                bool isMatch =
                    (idx1 < s.size()) &&
                    (s[idx1] == p[idx2] || p[idx2] == '?' || p[idx2] == '*');
                bool result;
                if (p[idx2] == '*') {
                    result =
                        curr[idx2 + 1] || (isMatch && prev[idx2]);
                } else {
                    result = isMatch && prev[idx2 + 1];
                }
                curr[idx2] = result;
            }
            prev=curr;
        }

        return prev[0];
    }
};