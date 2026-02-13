class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, queue<pair<int, int>> &q) {
        q.push({row, col});
        // cout<<row<<" "<<col<<endl;
        vis[row][col] = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1}; // LRUD
        for (int idx = 0; idx < 4; idx++) {
            int nrow = row + dx[idx];
            int ncol = col + dy[idx];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                ncol < grid[0].size()) {
                if (vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    dfs(nrow, ncol, grid, vis, q);
                    
                }
                    
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        bool f=false;
        for (int i = 0; i < n; i++) {  //o(n*m)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                  
                    dfs(i, j, grid, vis, q);
                    f=true;
                    break;
                }
               
            }
             if(f) break;
        }
        int required = 0;
        while (!q.empty()) {
            required++;
            int sz = q.size();
            // cout<<endl;
            for (int i = 0; i < sz; i++) {
                int row = q.front().first;
                int col = q.front().second;
                // cout<<row<<" "<<col<<" ";
                q.pop();
                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1}; // LRUD
                for (int idx = 0; idx < 4; idx++) {
                    int nrow = row + dx[idx];
                    int ncol = col + dy[idx];
                    if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                        ncol < grid[0].size()) {
                        if (vis[nrow][ncol] == 0) {
                            if (grid[nrow][ncol] == 1)
                                return (required-1);
                            q.push({nrow, ncol});
                            vis[nrow][ncol] = 1;
                        }
                    }
                }
            }
        }
        return (required-1);
    }
};