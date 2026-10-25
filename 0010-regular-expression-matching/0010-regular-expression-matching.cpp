class Solution {
public:
    bool helper(int idx1, int idx2, string& s, string& p) {
        if (idx2 == p.size())
            return (idx1 == s.size());

        bool isMatch =
            (idx1 < s.size()) && (s[idx1] == p[idx2] || p[idx2] == '.');
        bool result;
        if ((idx2 + 1) < p.size() && p[idx2 + 1] == '*') {
            result = helper(idx1, idx2 + 2, s, p) ||
                     (isMatch && helper(idx1 + 1, idx2, s, p));
        } else {
            result = (isMatch && helper(idx1 + 1, idx2 + 1, s, p));
        }

        return result;
    }
    bool isMatch(string s, string p) { return helper(0, 0, s, p); }
};