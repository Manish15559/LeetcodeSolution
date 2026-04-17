class Solution {
public:
    int minCost(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> dp(n, (k + n + 1));
        for (int i = 0; i < n; i++) {
            int cost = (k + i + 1);
            vector<int> cnt(n, 0);
            int len = 0;
            for (int j = i; j >= 0; j--) {
                cnt[nums[j]]++;
                if (cnt[nums[j]] == 2)
                    len += 2;
                else if (cnt[nums[j]] > 2)
                    len++;

                if (j == 0)
                    cost = min(cost, (k + len));
                else
                    cost = min(cost, (k + len + dp[j - 1]));
            }
            dp[i] = cost;
        }
        return dp[n - 1];
    }
};