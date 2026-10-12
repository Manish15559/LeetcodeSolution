class Solution {
public:
    bool check(int val, vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] > val)
            return false;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            if (row == n - 1 && col == n - 1) {
                return true;
            }
            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n) {
                    if (!vis[nrow][ncol] && grid[nrow][ncol] <= val) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high = (n * n) - 1;
        while(high > low) {
            int mid = (low + high) / 2;
            if (check(mid, grid) == true)
                high = mid;
            else
                low = mid + 1;
        }

        if (check(low, grid))
            return low;
        else
            return high;
    }
};