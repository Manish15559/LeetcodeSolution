class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<long long> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums

    for (int i = 0; i < n; i++) {
        vector<long long> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                long long up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; // Include the minimum path sum from above (previous row)
                else
                    up += 1e12; // A large value if moving up is not possible (out of bounds)

                long long left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                else
                    left += 1e12; // A large value if moving left is not possible (out of bounds)

                temp[j] = min(up, left); // Store the minimum path sum in temp[j]
            }
        }
        prev = temp; // Update the previous row with the current row
    }

    return prev[m - 1]; // The final result is stored in prev[m-1], representing the destination in the last column
        
    }
};