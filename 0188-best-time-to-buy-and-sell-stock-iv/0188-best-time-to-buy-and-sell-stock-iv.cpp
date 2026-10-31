class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(k+1, vector<int>(2, 0)));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int sell = 1; sell <= k; sell++) {
                for (int isBuying = 0; isBuying <= 1; isBuying++) {
                    int noAction = dp[idx + 1][sell][isBuying];
                    int action;
                    if (isBuying) {
                        action = dp[idx + 1][sell][0] - prices[idx];
                    } else {
                        action = dp[idx + 1][sell - 1][1] + prices[idx];
                    }
                    dp[idx][sell][isBuying] = max(action, noAction);
                }
            }
        }

        return dp[0][k][1];
    }
};
