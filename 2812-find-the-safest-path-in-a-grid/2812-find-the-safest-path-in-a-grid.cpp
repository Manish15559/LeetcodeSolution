class Solution {
public:
    bool isValid(int row, int col, int n) {

        return (row >= 0 && col >= 0 && row < n && col < n);
    }
    void spread(vector<vector<int>>& grid, vector<vector<int>>& spreadGrid,
                int n) {
        queue<pair<int, int>> q;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    q.push({row, col});
                    spreadGrid[row][col] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (isValid(nrow, ncol, n) && spreadGrid[nrow][ncol] == -1) {
                    spreadGrid[nrow][ncol] = 1 + spreadGrid[row][col];
                    q.push({nrow, ncol});
                }
            }
        }
    }

    bool check(int safe, vector<vector<int>>& spreadGrid, int n) {
        if (safe > spreadGrid[0][0])
            return false;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        vis[0][0] = 1;

        q.push({0, 0});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            if(row==(n-1)&&col==(n-1)) return true;
            
            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (isValid(nrow, ncol, n) && !vis[nrow][ncol]  &&
                    spreadGrid[nrow][ncol] >= safe) {
                        
                   vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
       
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> spreadGrid(n, vector<int>(n, -1));

     

        spread(grid, spreadGrid, n);
          

        int low = 0;
        int high = 2 * n - 2;
        while ((high-low)>1) {
            
            int mid = (low + high) / 2;
            
            if (check(mid, spreadGrid, n))
                low = mid;
            else
                high = mid - 1;
        }
        if(check(high,spreadGrid,n)) return high;
        return low;
    }
};