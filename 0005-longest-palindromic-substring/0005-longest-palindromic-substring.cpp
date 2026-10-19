class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (right > left) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {

        int n = s.size();
        if (n == 0)
            return "";
        int left = 0;
        int right = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                if (isPalindrome(s, l, r)) {
                    if ((right - left + 1) < (r - l + 1)) {
                        left = l;
                        right = r;
                    }
                }
            }
        }

        return s.substr(left, (right - left + 1));
    }
};