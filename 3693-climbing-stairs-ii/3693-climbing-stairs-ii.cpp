class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 1e9); // minimum cost to reach step i
        dp[0]=0;
        for (int idx = 1; idx <= n; idx++) {
            for (int step = 1; step <= 3; step++) {
                if ((idx - step) < 0)
                    break;
                int val = costs[idx - 1] + dp[idx - step] +
                          (step * step);
                dp[idx] = min(dp[idx], val);
            }
        }
        return dp[n];
    }
};