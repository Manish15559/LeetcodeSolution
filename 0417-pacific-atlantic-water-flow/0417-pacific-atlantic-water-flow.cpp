class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& isVisited,
             vector<vector<int>>& heights, int n, int m) {

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (!isValid(nrow, ncol, n, m))
                    continue;
                    cout<<nrow<<" "<<ncol<<endl;
                if (heights[row][col] <= heights[nrow][ncol] &&
                    isVisited[nrow][ncol] == false) {
                    isVisited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // 0 -> not visited
        // 1 -> atlantic
        // 2 -> pacific
        // 3 ->both
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> isPacific(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            isPacific[i][0] = true;
            q.push({i, 0});
        }
        for (int j = 1; j < m; j++) {
            isPacific[0][j] = true;
            q.push({0, j});
        }
        bfs(q, isPacific, heights, n, m);
        vector<vector<bool>> isAltantic(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            isAltantic[i][m - 1] = true;
            q.push({i, m - 1});
        }
        for (int j = 0; j < (m-1); j++) {
            isAltantic[n - 1][j] = true;
            q.push({n - 1, j});
        }
        bfs(q, isAltantic, heights, n, m);
        vector<vector<int>> ans;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (isPacific[row][col] && isAltantic[row][col])
                    ans.push_back({row, col});
            }
        }
        return ans;
    }
};