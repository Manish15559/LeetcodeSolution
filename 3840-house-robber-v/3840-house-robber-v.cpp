class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp1(n, 0), dp2(n, 0);
        dp1[0] = nums[0];
        for (int i = 1; i < n; i++) {
            // take
            if (colors[i] == colors[i - 1]) {
                // take
                dp1[i] = nums[i] + dp2[i - 1];

                // nottake
                dp2[i] = max(dp1[i - 1], dp2[i - 1]);
            } else {
                dp1[i] = nums[i] + max(dp1[i - 1], dp2[i - 1]);

                dp2[i] = max(dp1[i - 1], dp2[i - 1]);
            }
        }

        return max(dp1[n - 1], dp2[n - 1]);
    }
};