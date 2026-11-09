class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    long long dfs(int row, int col, vector<vector<long long>>& memo,
                  vector<vector<int>>& grid, int n, int m) {
        if (memo[row][col] != -1)
            return memo[row][col];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        long long tot = 1;
        int mod = 1e9 + 7;
        for (int idx = 0; idx < 4; idx++) {
            int nrow = row + dx[idx];
            int ncol = col + dy[idx];
            if (!isValid(nrow, ncol, n, m) ||
                grid[row][col] <= grid[nrow][ncol])
                continue;
            tot += dfs(nrow, ncol, memo,  grid, n, m);
            tot %= mod;
        }
        return memo[row][col] = tot;
    }
    int countPaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                dfs(row, col, memo, grid, n, m);
                ans += memo[row][col];
                ans %= mod;
            }
        }
        return ans;
    }
};