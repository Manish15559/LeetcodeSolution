class Solution {
public:
    bool check(int intialHealth, vector<vector<int>>& dungeon, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1e9));
        dp[0][0] = intialHealth + dungeon[0][0];
        if (dp[0][0] <= 0)
            return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    continue;
                int health = -1e9;
                if (i > 0)
                    health = max(health, dp[i - 1][j]);
                if (j > 0)
                    health = max(health, dp[i][j - 1]);

                if (health > 0 && (health + dungeon[i][j]) > 0)
                    dp[i][j] = health + dungeon[i][j];
            }
        }
        // cout<<intialHealth<<" "<<dp[n-1][m-1]<<endl;
        return dp[n - 1][m - 1] > 0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int low = 1;
        int high = 1e9;
        while (low < high) {
            int mid = (low + high) / 2;
            if (check(mid, dungeon, n, m))
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};