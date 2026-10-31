class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto word : wordDict)
            st.insert(word);
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[n] = 1;
        for (int left = n - 1; left >= 0; left--) {
            string curr;
            for (int right = left; right < n; right++) {
                curr.push_back(s[right]);
                if (st.find(curr) != st.end()) {
                    dp[left] = dp[right + 1];
                    if (dp[left] == true)
                        break;
                }
            }
        }
        return dp[0] == 1;
    }
};