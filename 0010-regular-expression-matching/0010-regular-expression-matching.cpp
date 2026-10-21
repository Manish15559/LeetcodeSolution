class Solution {
public:
    bool helper(int idx1, int idx2, string& s,  string& p) {
        if (idx2 < 0) {
            return idx1 < 0;
        } else if (idx1 < 0) {
            while (idx2 >= 0 && p[idx2] == '*') {
                if (p[idx2 - 1] == '*')
                    idx2--;
                else
                    idx2 -= 2;
            }
            if (idx2 < 0)
                return true;
            return false;
        }
         

        if (s[idx1] == p[idx2])
            return helper(idx1 - 1, idx2 - 1, s, p);
        else if (p[idx2] == '.')
            return helper(idx1 - 1, idx2 - 1, s, p);
        else if (p[idx2] == '*') {
            int prev = idx2 - 1;
          
            while (prev >= 0  &&p[prev] == '*') {
                if (p[prev] == '*')
                    prev--;
            }
           
            int op = helper(idx1, prev - 1, s, p);
            while (idx1 >= 0 && (s[idx1] == p[prev] || p[prev] == '.')) {

                op |= helper(idx1 - 1, prev - 1, s, p);
                idx1--;
            }
            return op | helper(idx1, prev - 1, s, p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return helper(n - 1, m - 1, s, p);
    }
};