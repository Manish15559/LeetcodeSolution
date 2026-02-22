class Solution {
public:
    int helper(int idx, int diff, vector<int>& rods, vector<vector<int>>& dp) {
        if (diff < 0)
            return -1e7;
        if (idx == rods.size()) {
            if (diff == 0)
                return 0;
            else
                return -1e7;
        }
        // cout<<idx<<" "<<diff
        if (dp[idx][diff] != -1e9)
            return dp[idx][diff];
        // take for first pole
        int op1 = rods[idx] + helper(idx + 1, diff - 2 * rods[idx], rods, dp);
        // take for secodn pole
        int op2 = helper(idx + 1, diff, rods, dp);
        // didnot take for any of them
        int op3 = helper(idx + 1, diff - rods[idx], rods, dp);

        return dp[idx][diff] = max({op1, op2, op3});
    }
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        int n = rods.size();
        for (auto it : rods)
            sum += it;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1e7));

        // for (int i = 0; i < n; i++)
            dp[n][0] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int diff = 0; diff <= sum; diff++) {

                int op1 = -1e7;
                if (diff >= (2 * rods[idx]))
                    op1 = rods[idx] + dp[idx + 1][diff - 2 * rods[idx]];
                // take for secodn pole
                int op2 = dp[idx + 1][diff];
                // didnot take for any of them
                int op3 = -1e7;
                if (diff >= (rods[idx]))
                    op3 = dp[idx + 1][diff - rods[idx]];

                dp[idx][diff] = max({op1, op2, op3});
            }
        }

        return dp[0][sum] < 0 ? 0 : dp[0][sum];
    }
};