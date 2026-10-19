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
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(n - 1, m - 1, word1, word2, dp);
    }
};