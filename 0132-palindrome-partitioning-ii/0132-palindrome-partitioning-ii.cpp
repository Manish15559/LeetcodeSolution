class Solution {
public:
bool isPalindrome(int l, int r, string &s) {
    while (r > l) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}


    int minCut(string s) {
        int n=s.size();
       
 vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX; // Large value to track minimum cuts
        for (int j = i; j >= 1; j--) {
            if (isPalindrome(j - 1, i - 1, s)) {
                if (j == 1) {
                    mini = 0; // No cuts needed for the whole substring
                } else {
                    mini = min(mini, dp[j - 1] + 1); // Add 1 cut
                }
            }
        }
        dp[i] = mini;
    }
    return dp[n];
      

    }
};