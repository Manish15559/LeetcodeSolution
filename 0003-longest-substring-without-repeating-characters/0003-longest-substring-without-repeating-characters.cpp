class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int longestSubstring=1; //longest substring without repeating a character

        int left=0; //starting point of the window
        unordered_map<char,int>track;
        for(int right=0;right<s.size();right++){
            track[s[right]]++;
            while(track[s[right]]>1&&left<right){
                track[s[left]]--;
                left++;
            }
            longestSubstring=max(longestSubstring,(right-left+1));

        }
        return longestSubstring;
        
    }
};