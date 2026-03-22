class Solution {
public:
    int find(int left, int right, bool turn, vector<int>& nums,
             vector<vector<int>>& dp) {
        if (left == right) {
            // cout<<turn<<endl;
            if (turn == true)
                return nums[left];
            else
                return (-1 * nums[left]);
        }
        if (dp[left][right] != -1)
            return dp[left][right];
        if (turn) {
            return max((find(left + 1, right, !turn, nums, dp) + nums[left]),
                       (find(left, right - 1, !turn, nums, dp) + nums[right]));
        } else {
            return min((find(left + 1, right, !turn, nums, dp) - nums[left]),
                       (find(left, right - 1, !turn, nums, dp) - nums[right]));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int turn = n % 2;
        for (int i = 0; i < n; i++) {
            if (turn)
                dp[i][i] = nums[i];
            else
                dp[i][i] = (-1 * nums[i]);
        }
        // turn=!turn;
        for (int len = 1; len < n; len++) {
            turn = !turn;
            for (int i = 0; (i + len) < n; i++) {
                int left = i;
                int right = i + len ;
                if (turn == true) {
                    dp[left][right] = max((dp[left + 1][right] + nums[left]),
                                          (dp[left][right - 1] + nums[right]));
                } else {
                    dp[left][right] = min((dp[left + 1][right] - nums[left]),
                                          (dp[left][right - 1] - nums[right]));
                }
            }
        }
        return dp[0][n - 1] >= 0;
    }
};