class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();
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
                        int curr = 0;
                        for (int col = y1; col <= y2; col++) {
                            curr += grid[row][col];
                        }
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
                        int curr = 0;
                        for (int row = x1; row <= x2; row++) {
                            curr += grid[row][col];
                        }

                        if (val != curr) {
                            f = false;
                            break;
                        }
                    }
                    if (f == false)
                        continue;

                    // upper diagonal
                    int row = x1;
                    int col = y1;
                    int curr = 0;
                    while (row <= x2 && col <= y2)
                        curr += grid[row++][col++];
                    if (curr != val)
                        continue;
                    row = x2;
                    col = y1;
                    curr = 0;
                    while (row >= x1 && col <= y2)
                        curr += grid[row--][col++];
                    if (curr != val)
                        continue;

                    ans = max(ans, (side + 1));
                }
            }
        }

        return ans;
    }
};