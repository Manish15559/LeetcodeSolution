class Solution {
public:
void checkPalindrome(int l,int r,string &s,vector<vector<bool>>&isPalindrome,int n){
    while(l>=0&&r<n){
        if(s[l]==s[r]){
            isPalindrome[l][r]=true;
            l--;
            r++;
        }
        else{
            break;
        }
    }
    return;
}


    int minCut(string s) {
        int n=s.size();
       
   vector<int> dp(n + 1, 0); // dp[i] stores minimum cuts needed for s[0...i-1]

    vector<vector<bool>>isPalindrome((n),vector<bool>((n),false));

    for(int idx=0;idx<n;idx++){
        checkPalindrome(idx,idx,s,isPalindrome,n);
        if(idx<(n-1))
        checkPalindrome(idx,idx+1,s,isPalindrome,n);
    }

    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX; // Initialize with a large value
        for (int j = i; j >= 1; j--) {
            if (isPalindrome[j-1][i-1]) {
                if (j == 1) {
                    mini = 0; // No cuts needed if s[0...i-1] itself is a palindrome
                } else {
                    mini = min(mini, dp[j - 1] + 1); // Update dp[i] with minimum cuts
                }
            }
        }
        dp[i] = mini; // Store the minimum cuts for s[0...i-1]
    }
    return dp[n]; // Return the result for the whole string

    }
};