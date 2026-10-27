class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, -1));
        queue<array<int, 3>> q;
        q.push({0, 0, k});
        best[0][0] = k;
        int step = -1;
        while(!q.empty()) {
            step++;
            int sz = q.size();
            while (sz--) {
                auto it = q.front();
                q.pop();
                int row = it[0];
                int col = it[1];
                if (row == (n - 1) && col == (m - 1))
                    return step;
                int val = it[2];
                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};
                for (int idx = 0; idx < 4; idx++) {
                    int nrow = row + dx[idx];
                    int ncol = col + dy[idx];
                    if (!isValid(nrow, ncol, n, m))
                        continue;
                    int nval = val - (grid[nrow][ncol] == 1);
                    if (best[nrow][ncol] < nval) {
                        q.push({nrow, ncol, nval});
                        best[nrow][ncol] = nval;
                    }
                }
            }
        }
        return -1;
    }
};