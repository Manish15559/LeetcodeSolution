class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        int tot = t.size();
        for (auto it : t) {
            count[it]++;
        }
        unordered_map<char, int> countInCurrentWindow;

        int left = 0;
        string ans="";
        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            if (count[ch] > countInCurrentWindow[ch]) {
                tot--;
            }
            countInCurrentWindow[ch]++;
            while (left <= right) {
                char remove = s[left];
                if (countInCurrentWindow[remove] > count[remove]) {
                    countInCurrentWindow[remove]--;
                    left++;
                } else {
                    break;
                }
            }
            // cout<<left<<" "<<right<<" "<<tot<<" "<<ans.size()<<endl;
            if (tot == 0 && (ans == "" || ans.size() >= (right - left + 1)))
                ans = s.substr(left, (right - left + 1));
        }
        return ans;
    }
};