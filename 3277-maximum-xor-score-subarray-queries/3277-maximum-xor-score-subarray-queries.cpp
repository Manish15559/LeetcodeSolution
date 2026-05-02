class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums,
                                   vector<vector<int>>& queries) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++){
            dp[i][1] = nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            int len = n - i;
            for (int j = 2; j <= len; j++) {
                int curr = dp[i][j - 1] ^ dp[i + 1][j - 1];
                dp[i][j] = curr;
            }
        }

    //    for(int j=1;j<=n;j++){
    //     for(int i=0;i<n;i++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    //    }
    //    cout<<endl;
        for (int i = n - 2; i >= 0; i--) {
            int len = n - i;
            for (int j = 2; j <= len; j++) {
                int curr = max({dp[i][j - 1], dp[i][j], dp[i + 1][j - 1]});
                dp[i][j] = curr;
            }
        }

        vector<int> ans;
        for (auto it : queries) {
            int idx = it[0];
            int len = it[1]-it[0]+1;
            ans.push_back(dp[idx][len]);
        }
        return ans;
    }
};