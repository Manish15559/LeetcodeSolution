class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> inWater(row, vector<int>(col, -1));
        for (int i = 0; i < row * col; i++) {
            cells[i][0]--;
            cells[i][1]--;
            inWater[cells[i][0]][cells[i][1]] = i;
        }

       

        priority_queue<vector<int>> pq;
        vector<vector<int>> lastDay(row, vector<int>(col, 0));
        for (int j = 0; j < col; j++) {
            pq.push({inWater[0][j], 0, j});
            lastDay[0][j] = inWater[0][j];
        }
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int day = it[0];
            int r = it[1];
            int c = it[2];
            if (r == (row - 1))
                return (day);
            if (day < lastDay[r][c])
                continue;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int idx = 0; idx < 4; idx++) {
                int nrow = r + dx[idx];
                int ncol = c + dy[idx];
                if (!(nrow >= 0 && ncol >= 0 && nrow < row && ncol < col))
                    continue;
                int daysRequired = min(day, inWater[nrow][ncol]);
                if (daysRequired > lastDay[nrow][ncol]) {
                    lastDay[nrow][ncol] = daysRequired;
                    pq.push({daysRequired, nrow, ncol});
                }
            }
        }
        return 0;
    }
};