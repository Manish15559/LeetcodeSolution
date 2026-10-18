class Solution {
public:
    bool search(int curr, int row, int col, vector<vector<char>>& board,
                string& word, int n, int m) {
        if (curr == word.size())
            return true;
        char saveCharacter = board[row][col];
        board[row][col] = '#';
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int idx = 0; idx < 4; idx++) {
            int nrow = row + dx[idx];
            int ncol = col + dy[idx];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                board[nrow][ncol] == word[curr]) {
                if (search(curr + 1, nrow, ncol, board, word, n, m)) {
                    board[row][col] = saveCharacter;
                    return true;
                }
            }
        }
        board[row][col] = saveCharacter;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (board[row][col] == word[0]) {
                    if (search(1, row, col, board, word, n, m))
                        return true;
                }
            }
        }
        return false;
    }
};