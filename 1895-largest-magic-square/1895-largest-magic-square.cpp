class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prefRow(n+1,vector<int>(m+1,0));
        vector<vector<int>>prefCol(n+1,vector<int>(m+1,0));
        vector<vector<int>>diagonal1(n+1,vector<int>(m+1,0));
        vector<vector<int>>diagonal2(n+1,vector<int>(m+2,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefRow[i][j]=prefRow[i][j-1]+grid[i-1][j-1];
                prefCol[i][j]=prefCol[i-1][j]+grid[i-1][j-1];
                diagonal1[i][j]=diagonal1[i-1][j-1]+grid[i-1][j-1];
                diagonal2[i][j]=diagonal2[i-1][j+1]+grid[i-1][j-1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = min((i), (j));
                for (int side = ans; side <= len; side++) {
                    int x1 = i - side;
                    int x2 = i;
                    int y1 = j - side;
                    int y2 = j;
                    int val = -1;
                    bool f = true;

                    for (int row = x1; row <= x2; row++) {
                        int curr = prefRow[row+1][y2+1]-prefRow[row+1][y1];
                        if (val == -1)
                            val = curr;
                        else if (val != curr) {
                            f = false;
                            break;
                        }
                    }
                    if (f == false)
                        continue;

                    for (int col = y1; col <= y2; col++) {
                        int curr = prefCol[x2+1][col+1]-prefCol[x1][col+1];
                    

                        if (val != curr) {
                            f = false;
                            break;
                        }
                    }
                    if (f == false)
                        continue;

                    // upper diagonal
                    int curr = diagonal1[x2+1][y2+1]-diagonal1[x1][y1];
                    if (curr != val)
                        continue;
                    curr =diagonal2[x2+1][y1+1]-diagonal2[x1][y2+2];
                    if (curr != val)
                        continue;

                    ans = max(ans, (side + 1));
                }
            }
        }

        return ans;
    }
};