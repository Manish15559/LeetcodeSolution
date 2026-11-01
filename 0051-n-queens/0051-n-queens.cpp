class Solution {
public:
    void tryAllPossibility(int col, int n, vector<string>& currArrangement,
                           vector<vector<string>>& possibleWays,
                           vector<bool>& rowCheck,
                           vector<bool>& lowerDiagonalCheck,
                           vector<bool>& upperDiagonalCheck) {
        if (col == n) {
            possibleWays.push_back(currArrangement);
            return;
        }
        for (int row = 0; row < n; row++) {
            int rowIdx = row;
            int lowerDiagonalIdx = row + col;
            int upperDiagonalIdx = (n - 1) + (row - col);
            if (!rowCheck[rowIdx] && !lowerDiagonalCheck[lowerDiagonalIdx] &&
                !upperDiagonalCheck[upperDiagonalIdx]) {
                currArrangement[row][col] = 'Q';
                rowCheck[rowIdx] = true;
                lowerDiagonalCheck[lowerDiagonalIdx] = true;
                upperDiagonalCheck[upperDiagonalIdx] = true;
                tryAllPossibility(col + 1, n, currArrangement, possibleWays,
                                  rowCheck, lowerDiagonalCheck,
                                  upperDiagonalCheck);
                currArrangement[row][col] = '.';
                rowCheck[rowIdx] = false;
                lowerDiagonalCheck[lowerDiagonalIdx] = false;
                upperDiagonalCheck[upperDiagonalIdx] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> possibleWays;
        vector<string> currArrangement;
        string str(n, '.');
        for (int i = 0; i < n; i++) {
            currArrangement.push_back(str);
        }
        vector<bool> rowCheck(n, false), lowerDiagonalCheck(2 * n - 1, false),
            upperDiagonalCheck(2 * n - 1, false);

        tryAllPossibility(0, n, currArrangement, possibleWays, rowCheck,
                          lowerDiagonalCheck, upperDiagonalCheck);
        return possibleWays;

        //                     (i+j)     =>(n-1+(i-j));
        //  (0,0)(0,1)(0,2)(0,3) => 1 2 3 4 5 6 7 (1,0)(1,1)(1,2)(1,3)    +1,-1,
        //  -1,-1  0,-1     (2*(n-1)+1)  2*n-1   => 4+-3, -2, -1,0,1,2,3
        //  (2,0)(2,1)(2,2)(2,3)
        //  (3,0)(3,1)(3,2)(3,3)
    }
};