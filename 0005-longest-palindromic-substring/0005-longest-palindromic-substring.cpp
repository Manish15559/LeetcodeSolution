class Solution {
public:
    pair<int,int> findLongestPalindrome(string& s, int left, int right, int n) {
        while (left>=0&&right<n&&s[left] == s[right]) {
           
            left--;
            right++;
            // if(left==0||right)
        }
        return {left+1, right-1};
    }
    string longestPalindrome(string s) {

        int n = s.size();
        if (n == 0)
            return "";
        int left = 0;
        int right = 0;

        for (int idx = 0; idx < n; idx++) {
           

            if (idx > 0 && s[idx - 1] == s[idx]) {
                pair<int, int> rangeOfPalindrome =
                    findLongestPalindrome(s, idx - 1, idx, n);
                if ((right - left + 1) <
                    (rangeOfPalindrome.second - rangeOfPalindrome.first + 1)) {
                    right = rangeOfPalindrome.second;
                    left = rangeOfPalindrome.first;
                }
            }
            pair<int, int> rangeOfPalindrome =
                findLongestPalindrome(s, idx, idx, n);
            if ((right - left + 1) <
                (rangeOfPalindrome.second - rangeOfPalindrome.first + 1)) {
                right = rangeOfPalindrome.second;
                left = rangeOfPalindrome.first;
            }
        }
        cout<<left<<" "<<right<<endl;

        return s.substr(left, (right - left + 1));
    }
};