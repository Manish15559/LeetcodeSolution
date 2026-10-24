class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //   idx 0 1 3    0 1 3                   {j, n-1-i}
        //     0 1 2 3    7 4 1        {0,0}  => {0,2}   {0,1}  => {1,2}  {0,2}
        //     => {2,2} 1 4 5 6    8 5 2        {1,0}  => {0,1}   {1,1}   =>
        //     {1,1}  {1,2} => {2,1} 2 7 8 9    9 6 3
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[j][n-1-i] = temp[i][j];
            }
        }
     
    }
};