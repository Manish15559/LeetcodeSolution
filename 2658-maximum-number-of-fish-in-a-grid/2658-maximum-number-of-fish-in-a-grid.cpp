class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis, int n, int m) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int tot = grid[row][col];
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    if (!vis[nrow][ncol] && grid[nrow][ncol] > 0) {
                        vis[nrow][ncol] = 1;
                        tot += grid[nrow][ncol];
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return tot;
    }
    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    vis[i][j] = 1;
                    int curr = bfs(i, j, grid, vis, n, m);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};