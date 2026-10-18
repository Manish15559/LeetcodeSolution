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
        vector<int>prev(required+1,0),curr(required+1,0);

       prev[0]=1;

        for (int idx = 1; idx < n; idx++) {
            for (int sum = 0; sum <= required; sum++) {
                bool op1 = prev[sum];
                bool op2 = false;
                if (sum >= nums[idx]) {
                    op2 = prev[sum - nums[idx]];
                }

                curr[sum] = op1 || op2;
            }
            prev=curr;
        }

        return prev[required];
    }
};