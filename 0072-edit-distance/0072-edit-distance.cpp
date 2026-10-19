class Solution {
public:
    int helper(int idx1, int idx2, string& word1, string& word2,
               vector<vector<int>>& dp) {
        if (idx1 < 0)
            return (idx2 + 1);
        if (idx2 < 0)
            return (idx1 + 1);
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (word1[idx1] == word2[idx2])
            return dp[idx1][idx2] =
                       helper(idx1 - 1, idx2 - 1, word1, word2, dp);
        int op1 = helper(idx1, idx2 - 1, word1, word2, dp);
        int op2 = helper(idx1 - 1, idx2, word1, word2, dp);
        int op3 = helper(idx1 - 1, idx2 - 1, word1, word2, dp);

        return dp[idx1][idx2] = (1 + min({op1, op2, op3}));
    }
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int i = 1; i <= m; i++)
            dp[0][i] = i;

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (word1[idx1 - 1] == word2[idx2 - 1])
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
                else {
                    int op1 = dp[idx1][idx2 - 1];
                    int op2 = dp[idx1 - 1][idx2];
                    int op3 = dp[idx1 - 1][idx2 - 1];

                    dp[idx1][idx2] = (1 + min({op1, op2, op3}));
                }
            }
        }

        return dp[n][m];
    }
};