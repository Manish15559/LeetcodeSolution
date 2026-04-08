class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if(n==1&&m==1) return 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            
            pq.pop();
            int value = it.first;
            int row = it.second.first;
            int col = it.second.second;
           
            if (value > dp[row][col])
                continue;

            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                int nvalue = value + ((idx + 1) != grid[row][col]);
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    if (nvalue < dp[nrow][ncol]) {
                        dp[nrow][ncol] = nvalue;
                        pq.push({nvalue, {nrow, ncol}});
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};