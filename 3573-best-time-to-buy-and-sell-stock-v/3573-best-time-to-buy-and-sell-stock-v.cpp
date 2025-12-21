const int N = 1e3 + 10;
long long dp[N][N / 2][3];

class Solution {
public:
    long long helper(int idx, int type, int k, vector<int>& prices) {
        if (idx == prices.size()) {
            if (type == 0)
                return 0;
            else
                return (-1e15);
        }
        if (dp[idx][k][type] != -1)
            return dp[idx][k][type];

        // type=0 //nothing
        if (type == 0) {
            // skip
            long long op1 = helper(idx + 1, type, k, prices);

            // buy
            long long op2 = 0;
            // sell
            long long op3 = 0;
            if (k > 0) {
                op2 = helper(idx + 1, 1, (k - 1), prices) - prices[idx];
                op3 = helper(idx + 1, 2, (k - 1), prices) + prices[idx];
            }

            return dp[idx][k][type] = max({op1, op2, op3});
        } else if (type == 1) {
            // skip
            long long op1 = helper(idx + 1, type, k, prices);

            // sell
            long long op2 = helper(idx + 1, 0, k, prices) + prices[idx];

            return dp[idx][k][type] = max(op1, op2);

        }

        else {
            // skip
            long long op1 = helper(idx + 1, type, k, prices);

            // buy
            long long op2 = helper(idx + 1, 0, k, prices) - prices[idx];

            return dp[idx][k][type] = max(op1, op2);
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, 0, sizeof(dp));
        int n = prices.size();

        for (int i = 0; i <= k; i++) {
            dp[n][i][1] = -1e15;
            dp[n][i][2] = -1e15;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int i = 0; i <= k; i++) {
                for (int type = 0; type <= 2; type++) {

                    if (type == 0) {

                        long long op1 = dp[(idx + 1)][i][type];

                        long long op2 = 0;

                        long long op3 = 0;
                        if (i > 0) {
                            op2 = dp[idx + 1][i - 1][1] - prices[idx];
                            op3 = dp[idx + 1][i - 1][2] + prices[idx];
                        }

                        dp[idx][i][type] = max({op1, op2, op3});
                    } else if (type == 1) {
                        // skip
                        long long op1 = dp[(idx + 1)][i][type];

                        // sell
                        long long op2 = dp[idx + 1][i][0] + prices[idx];

                        dp[idx][i][type] = max(op1, op2);

                    }

                    else {
                        // skip
                        long long op1 = dp[(idx + 1)][i][type];

                        // buy
                        long long op2 = dp[idx + 1][i][0] - prices[idx];

                        dp[idx][i][type] = max(op1, op2);
                    }
                }
            }
        }

       return  dp[0][k][0];
    }
};