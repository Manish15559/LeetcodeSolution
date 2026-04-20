
bool comp(vector<int>& a, vector<int>& b) { return a[2] > b[2]; }

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        sort(sources.begin(), sources.end(), comp);
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        queue<vector<int>> q;
        for (auto it : sources) {
            matrix[it[0]][it[1]] = it[2];
            q.push(it);
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it[0];
            int col = it[1];
            int color = it[2];
            for (int idx = 0; idx < 4; idx++) {
                int nrow = row + dx[idx];
                int ncol = col + dy[idx];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    if (matrix[nrow][ncol] == 0) {
                        matrix[nrow][ncol] = color;
                        q.push({nrow, ncol, color});
                    }
                }
            }
        }

        return matrix;
    }
};