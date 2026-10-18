class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> required, inCurrentWindow;
        int totRequired = 0;
        for (auto ch : t) {
            required[ch]++;
            totRequired++;
        }
        int left = 0;
        string ans = "";
        for (int right = 0; right < n; right++) {
            inCurrentWindow[s[right]]++;
            if (required[s[right]] >= inCurrentWindow[s[right]])
                totRequired--;
            while (left <= right &&
                   required[s[left]] < inCurrentWindow[s[left]]) {
                inCurrentWindow[s[left]]--;
                left++;
            }
            if (totRequired == 0) {
                if (ans == "" || ans.size() > (right - left + 1))
                    ans = s.substr(left, (right - left + 1));
            }
        }
        return ans;
    }
};