class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefSum(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int sum = matrix[row][col];
                if (row > 0)
                    sum += prefSum[row - 1][col];
                if (col > 0)
                    sum += prefSum[row][col - 1];
                if (row > 0 && col > 0)
                    sum -= prefSum[row - 1][col - 1];
                prefSum[row][col] = sum;
               
            }
          
        }
        int ans = 0;
        for (int row2 = 0; row2 < n; row2++) {
            for (int col2 = 0; col2 < m; col2++) {
                int sz = 1;
                int row1 = row2;
                int col1 = col2;
                while (row1 >= 0 && col1 >= 0) {

                    int requiredOne = sz * sz;
                    int countOne = prefSum[row2][col2];
                    if (row1 > 0)
                        countOne -= prefSum[row1 - 1][col2];
                    if (col1 > 0)
                        countOne -= prefSum[row2][col1 - 1];
                    if (row1 > 0 && col1 > 0)
                        countOne+=prefSum[row1 - 1][col1 - 1];
                         
                    if (countOne == requiredOne){
                       
                        ans++;
                    }
                    sz++;
                    row1--;
                    col1--;
                }
            }
        }
        return ans;
    }
};