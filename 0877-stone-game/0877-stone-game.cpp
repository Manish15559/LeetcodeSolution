class Solution {
public:
    int helper(bool turn, int left, int right, vector<int>& piles,
               vector<vector<vector<int>>>& dp) {
        if (left > right)
            return 0;
        if (dp[left][right][turn] != -1)
            return dp[left][right][turn];
        if (turn)
            return dp[left][right][turn] =
                       max((piles[left] +
                            helper(false, left + 1, right, piles, dp)),
                           (piles[right] +
                            helper(false, left, right - 1, piles, dp)));
        else
            return dp[left][right][turn] = min(
                       (helper(true, left + 1, right, piles, dp) - piles[left]),
                       (helper(true, left, right - 1, piles, dp) -
                        piles[right]));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = 0; i < n; i++) {
            dp[i][i][1] = piles[i];
            dp[i][i][0] = -piles[i];
        }

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left + 1; right < n; right++) {
                for (int turn = 0; turn <= 1; turn++) {
                    if (turn)
                        dp[left][right][turn] =
                            max((piles[left] + dp[left + 1][right][0]),
                                (piles[right] + dp[left][right - 1][0]));
                    else
                        dp[left][right][turn] =
                            min((dp[left + 1][right][1] - piles[left]),
                                (dp[left][right - 1][1] - piles[right]));
                }
            }
        }

        return dp[0][n - 1][1];
    }
};