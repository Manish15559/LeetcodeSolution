class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], (1 + dp[j]));
            }
        }

        int maxLength = 0;
        for (auto it : dp)
            maxLength = max(it, maxLength);

        return maxLength;
    }
};