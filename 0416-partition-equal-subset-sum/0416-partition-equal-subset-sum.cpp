class Solution {
public:
    bool helper(int idx, int required, vector<int>& nums,
                vector<vector<int>>& dp) {
        if (required == 0)
            return true;
        if (idx == 0) {
            return nums[idx] == required;
        }
        if (dp[idx][required] != -1)
            return dp[idx][required];
        bool op1 = helper(idx - 1, required, nums, dp);
        bool op2 = false;
        if (required >= nums[idx]) {
            op2 = helper(idx - 1, required - nums[idx], nums, dp);
        }

        return dp[idx][required] = op1 || op2;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;

        int required = sum / 2;
        vector<vector<int>> dp(n, vector<int>(required + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        if (nums[0] <= required)
            dp[0][nums[0]] = 1;

        for (int idx = 1; idx < n; idx++) {
            for (int sum = 1; sum <= required; sum++) {
                bool op1 = dp[idx - 1][sum];
                bool op2 = false;
                if (sum >= nums[idx]) {
                    op2 = dp[idx - 1][sum - nums[idx]];
                }

                dp[idx][sum] = op1 || op2;
            }
        }

        return dp[n - 1][required];
    }
};