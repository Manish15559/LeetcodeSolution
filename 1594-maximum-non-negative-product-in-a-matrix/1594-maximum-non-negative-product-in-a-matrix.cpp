class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<long long, long long>>> matrix(
            n, vector<pair<long long, long long>>(m, {INT_MIN, INT_MAX}));
        matrix[0][0].first = matrix[0][0].second = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    continue;
                if ((i - 1) >= 0) {
                    matrix[i][j].first =
                        max((matrix[i - 1][j].first * grid[i][j]),
                            (matrix[i - 1][j].second * grid[i][j]));
                    matrix[i][j].second =
                        min((matrix[i - 1][j].first * grid[i][j]),
                            (matrix[i - 1][j].second * grid[i][j]));
                }
                if ((j - 1) >= 0) {
                    matrix[i][j].first =
                        max({(matrix[i][j - 1].first * grid[i][j]),
                             (matrix[i][j - 1].second * grid[i][j]),
                             matrix[i][j].first});
                    matrix[i][j].second =
                        min({(matrix[i][j - 1].first * grid[i][j]),
                             (matrix[i][j - 1].second * grid[i][j]),
                             matrix[i][j].second});
                }
            }
        }
        if (matrix[n - 1][m - 1].first < 0)
            return -1;
            int mod=1e9+7;
        return matrix[n - 1][m - 1].first%mod;
    }
};