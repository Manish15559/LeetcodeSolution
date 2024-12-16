class Solution {
public:

    int minDistance(string word1, string word2) {

    int length1 = word1.size(); // Length of word1
    int length2 = word2.size(); // Length of word2

    // Create a DP table to store the minimum edit distances
    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

    // Initialize the base cases:
    // If word2 is empty, we need to delete all characters of word1
    for (int i = 0; i <= length1; i++) {
        dp[i][0] = i;
    }

    // If word1 is empty, we need to insert all characters of word2
    for (int j = 0; j <= length2; j++) {
        dp[0][j] = j;
    }

    // Fill the DP table using the recurrence relation
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            // If the characters are the same, no operation is needed
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            // If the characters are different, choose the minimum of the three operations:
            // Insert, Delete, Replace
            else {
                dp[i][j] = 1 + min({
                    dp[i][j - 1],    // Insert a character
                    dp[i - 1][j],    // Delete a character
                    dp[i - 1][j - 1] // Replace a character
                });
            }
        }
    }

    // The result is stored in the last cell of the DP table
    return dp[length1][length2];

        
    }
};