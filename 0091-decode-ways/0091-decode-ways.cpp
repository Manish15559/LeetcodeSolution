class Solution {
public:
    bool doubleDigitValidation(int idx, string& s) {
        if ((idx - 1) >= 0 && s[idx - 1] != '0') {
            int digit = (s[idx - 1] - '0') * 10 + (s[idx] - '0');
            if (digit > 0 && digit <= 26)
                return true;
        }
        return false;
    }
    int helper(int idx, string& s) {
        if (idx < 0)
            return 1;

        int op1 = (s[idx] != '0') ? helper(idx - 1, s) : 0;
        int op2 = doubleDigitValidation(idx, s) ? helper(idx - 2, s) : 0;

        return op1 + op2;
    }
    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, 0);
        dp[0] = (s[0] != '0') ? 1 : 0;
        if(n==1) return dp[0];
        dp[1] = (s[1] != '0') ? dp[0] : 0;
        dp[1] += (doubleDigitValidation(1, s) ? 1 : 0);
        for (int i =2; i < n; i++) {
            int tot = 0;
            if (s[i] != '0')
                tot += dp[i - 1];
            if (doubleDigitValidation(i,s))
                tot += dp[i - 2];
            dp[i] = tot;
        }
        return dp[n - 1];
    }
};