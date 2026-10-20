class Solution {
public:
    bool isValid(char ch, int row, int col,
                 vector<unordered_set<char>>& rowTracker,
                 vector<unordered_set<char>>& colTracker,
                 vector<vector<unordered_set<char>>>& matrixTracker) {
        if (rowTracker[row].find(ch) != rowTracker[row].end())
            return false;
        if (colTracker[col].find(ch) != colTracker[col].end())
            return false;
        int r = row / 3;
        int c = col / 3;
        if (matrixTracker[r][c].find(ch) != matrixTracker[r][c].end())
            return false;

        return true;
    }

    bool helper(int row, int col, vector<vector<char>>& board,
                vector<unordered_set<char>>& rowTracker,
                vector<unordered_set<char>>& colTracker,
                vector<vector<unordered_set<char>>>& matrixTracker) {

        if (row >= 9)
            return true;

        if (board[row][col] == '.') {

            for (char ch = '1'; ch <= '9'; ch++) {
                if (isValid(ch, row, col, rowTracker, colTracker,
                            matrixTracker)) {
                    board[row][col] = ch;
                    rowTracker[row].insert(ch);
                    colTracker[col].insert(ch);
                    int r = row / 3;
                    int c = col / 3;
                    matrixTracker[r][c].insert(ch);
                    int nrow = row;
                    int ncol = col + 1;
                    if (ncol >= 9) {
                        nrow++;
                        ncol = 0;
                    }
                    if (helper(nrow, ncol, board, rowTracker, colTracker,
                               matrixTracker))
                        return true;
                    rowTracker[row].erase(ch);
                    colTracker[col].erase(ch);

                    matrixTracker[r][c].erase(ch);
                    board[row][col]='.';
                }
            }
            return false;
        }
        int nrow = row;
        int ncol = col + 1;
        if (ncol >= 9) {
            nrow++;
            ncol = 0;
        }
        return helper(nrow, ncol, board, rowTracker, colTracker, matrixTracker);
    }
    void solveSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<unordered_set<char>> rowTracker(n), colTracker(m);
        vector<vector<unordered_set<char>>> matrixTracker(
            3, vector<unordered_set<char>>(3));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int row = i / 3;
                int col = j / 3;
                if (board[i][j] != '.') {
                    rowTracker[i].insert(board[i][j]);
                    colTracker[j].insert(board[i][j]);
                    matrixTracker[row][col].insert(board[i][j]);
                }
            }
        }

        helper(0, 0, board, rowTracker, colTracker, matrixTracker);
    }
};