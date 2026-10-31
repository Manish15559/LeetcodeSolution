class Solution {
public:
    int helper(int idx, bool isSelling, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (idx == prices.size())
            return 0;
        if (dp[idx][isSelling] != -1)
            return dp[idx][isSelling];
        int noAction = helper(idx + 1, isSelling, prices, dp);
        int action;
        if (isSelling) {
            action = helper(idx + 1, false, prices, dp) + prices[idx];

        } else {
            action = helper(idx + 1, true, prices, dp) - prices[idx];
        }

        return dp[idx][isSelling] = max(action, noAction);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2,0),curr(2,0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int isSelling = 0; isSelling <= 1; isSelling++) {
                int noAction = prev[isSelling];
                int action;
                if (isSelling) {
                    action = prev[0] + prices[idx];

                } else {
                    action = prev[1] - prices[idx];
                }

                curr[isSelling] = max(action, noAction);
            }
            prev=curr;
        }

        return prev[0];
    }
};