class Solution {
public:
    int countVowelStrings(int n) {
        int MOD=1e9+7;
         vector<vector<int>> dp(n + 1, vector<int>(6, 0));

    // Initialize for length 1
    for (int j = 1; j <= 5; ++j)
        dp[1][j] = dp[1][j - 1] + 1;

    // Fill DP table
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    return dp[n][5];
        
    }
};