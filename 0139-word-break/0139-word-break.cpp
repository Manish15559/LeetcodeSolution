class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.size();  // Length of the input string
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());  // Store dictionary words in a set for O(1) lookup
    vector<bool> dp(n + 1, false);  // DP array to store if s[0..i-1] can be segmented
    dp[0] = true;  // An empty string is always segmentable
    
    // Outer loop: Iterate over the end position of the current substring
    for (int right = 1; right <= n; ++right) {
        // Inner loop: Check all possible starting positions for the current ending position
        for (int left = right; left >= 1; --left) {
            int len = right - left + 1;  // Length of the current substring
            string subStr = s.substr(left - 1, len);  // Extract the substring
            if (wordSet.find(subStr) != wordSet.end() && dp[left - 1] == true) {
                dp[right] = true;  // If substring found in the dictionary and previous part is segmentable
                break;  // No need to check further as this position is marked as segmentable
            }
        }
    }
    
    return dp[n];  
        
    }
};