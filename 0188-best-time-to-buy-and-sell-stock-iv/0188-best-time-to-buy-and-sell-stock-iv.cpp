class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        
            vector<vector<int>>curr(k+1, vector<int>(2, 0));
            vector<vector<int>>prev(k+1, vector<int>(2, 0));


        for (int idx = n - 1; idx >= 0; idx--) {
            for (int sell = 1; sell <= k; sell++) {
                for (int isBuying = 0; isBuying <= 1; isBuying++) {
                    int noAction = prev[sell][isBuying];
                    int action;
                    if (isBuying) {
                        action = prev[sell][0] - prices[idx];
                    } else {
                        action = prev[sell - 1][1] + prices[idx];
                    }
                    curr[sell][isBuying] = max(action, noAction);
                }
            }

            prev=curr;
        }

        return curr[k][1];
    }
};
