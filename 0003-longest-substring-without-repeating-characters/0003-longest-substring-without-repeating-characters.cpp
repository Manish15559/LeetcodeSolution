class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int longestSubstring =
            1; // longest substring without repeating a character

        int left = 0; // starting point of the window
        vector<int> unSeen(256, -1);
        for (int right = 0; right < s.size(); right++) {
            char currentCharacter = s[right];
            if (unSeen[currentCharacter] >= left) {
                left = unSeen[currentCharacter] + 1;
            }
            unSeen[currentCharacter] = right;
            longestSubstring = max(longestSubstring, (right - left + 1));
        }
        return longestSubstring;
    }
};