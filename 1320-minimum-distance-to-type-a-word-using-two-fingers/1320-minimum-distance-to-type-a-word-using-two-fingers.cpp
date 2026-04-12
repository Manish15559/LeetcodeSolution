class Solution {
public:
    int helper(int idx, int ch1, int ch2, string& word,
               vector<vector<vector<int>>>& dp) {
        // cout<<ch1<<" "<<ch2<<endl;

        if (idx == word.size())
            return 0;
        if (dp[idx][ch1][ch2] != -1)
            return dp[idx][ch1][ch2];
        int row1 = ch1 / 6;
        int col1 = ch1 % 6;
        int row2 = ch2 / 6;
        int col2 = ch2 % 6;
        int row = (word[idx] - 'A') / 6;
        int col = (word[idx] - 'A') % 6;
        int op1 = abs(row1 - row) + abs(col1 - col) +
                  helper(idx + 1, (word[idx] - 'A'), ch2, word, dp);
        int op2 = abs(row2 - row) + abs(col2 - col) +
                  helper(idx + 1, ch1, (word[idx] - 'A'), word, dp);

        return dp[idx][ch1][ch2] = min(op1, op2);
    }
    int minimumDistance(string word) {

        int n = word.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(26, vector<int>(26, 1e9)));

        int mini = 1e9;
        for (int ch1 = 0; ch1 < 26; ch1++) {
            for (int ch2 = 0; ch2 < 26; ch2++) {
                dp[n][ch1][ch2] = 0;
            }
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int ch1 = 0; ch1 < 26; ch1++) {
                for (int ch2 = 0; ch2 < 26; ch2++) {
                    int row1 = ch1 / 6;
                    int col1 = ch1 % 6;
                    int row2 = ch2 / 6;
                    int col2 = ch2 % 6;
                    int row = (word[idx] - 'A') / 6;
                    int col = (word[idx] - 'A') % 6;
                    int op1 = abs(row1 - row) + abs(col1 - col) +
                              dp[idx + 1][(word[idx] - 'A')][ch2];
                    int op2 = abs(row2 - row) + abs(col2 - col) +
                              dp[idx + 1][ch1][(word[idx] - 'A')];

                    dp[idx][ch1][ch2] = min(op1, op2);
                }
            }
        }
        for (int ch1 = 0; ch1 < 26; ch1++) {
            for (int ch2 = 0; ch2 < 26; ch2++) {
                mini = min(mini, dp[0][ch1][ch2]);
            }
        }

        return mini;
    }
};