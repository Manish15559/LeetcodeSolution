class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& dungeon, int n, int m,
               vector<vector<int>>& dp) {
        if (row == (n - 1) && col == (m - 1))
            return (dungeon[row][col] > 0) ? 1 : ((-1 * dungeon[row][col]) + 1);
        if (dp[row][col] != -1)
            return dp[row][col];
        int goLeft = 1e9;
        if (col < (m - 1))
            goLeft = helper(row, col + 1, dungeon, n, m, dp);
        int goRight = 1e9;
        if (row < (n - 1))
            goRight = helper(row + 1, col, dungeon, n, m, dp);
        int miniHealthRequired = min(goLeft, goRight);
        int required = miniHealthRequired - dungeon[row][col];
        return dp[row][col] = (required <= 0) ? 1 : required;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        if (dungeon[n - 1][m - 1] > 0)
            dp[n - 1][m - 1] = 1;
        else
            dp[n - 1][m - 1] = -1 * dungeon[n - 1][m - 1] + 1;
        for (int row = n - 1; row >= 0; row--) {
            for (int col = m - 1; col >= 0; col--) {
                if (row == (n - 1) && col == (m - 1))
                    continue;
                int goRight = 1e9;
                if (col < (m - 1))
                    goRight = dp[row][col + 1];
                int goDown = 1e9;
                if (row < (n - 1))
                    goDown = dp[row + 1][col];
                int required = min(goRight, goDown) - dungeon[row][col];
                if (required > 0)
                    dp[row][col] = required;
                else
                    dp[row][col] = 1;
            }
        }

        return dp[0][0];
    }
};