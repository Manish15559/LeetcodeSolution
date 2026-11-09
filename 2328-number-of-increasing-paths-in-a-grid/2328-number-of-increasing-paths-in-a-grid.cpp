class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    int countPaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> arr;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                arr.push_back({grid[row][col], row, col});
            }
        }
        sort(arr.begin(), arr.end());
        vector<vector<long long>> memo(n, vector<long long>(m, 0));
        long long ans = 0;
        int mod = 1e9 + 7;
        for (auto it : arr) {
            int row = it[1];
            int col = it[2];
            long long tot = 0;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (!isValid(nrow, ncol, n, m))
                    continue;
                if (grid[row][col] > grid[nrow][ncol]) {
                    tot = (tot + memo[nrow][ncol]) % mod;
                }
            }
            tot++;
           
            ans = (ans + tot) % mod;
             
            memo[row][col]=tot%mod;
        }
        return ans;
    }
};