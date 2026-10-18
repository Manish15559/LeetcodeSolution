class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto it : nums)
            st.insert(it);
        if(nums.size()==0) return 0;

        int longest = 1;
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int length = 1;
                while (st.find(it + length) != st.end())
                    length++;

                longest = max(longest, length);
            }
        }

        return longest;
    }
};