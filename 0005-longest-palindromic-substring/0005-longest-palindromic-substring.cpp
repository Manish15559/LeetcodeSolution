class Solution {
public:
    string findLongestPalindrome(string& s, int left, int right, int n) {
        while (left > 0 && right < (n - 1) && s[left-1] == s[right+1]) {

            left--;
            right++;
            // if(left==0||right)
        }
        return s.substr(left, (right - left + 1));
    }
    string longestPalindrome(string s) {

        int n = s.size();
        if (n == 0)
            return "";
        string ans = "";
        for (int idx = 0; idx < n; idx++) {

            if (idx > 0 && s[idx - 1] == s[idx]) {
                string longestStr = findLongestPalindrome(s, idx - 1, idx, n);
                if (longestStr.size() > ans.size())
                    ans = longestStr;
            }
            string longestStr = findLongestPalindrome(s, idx, idx, n);
            if (longestStr.size() > ans.size())
                ans = longestStr;
        }

        return ans;
    }
};