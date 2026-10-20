class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int used = 0;
        int maxLength = 0;
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                used++;
            while (left <= right && used > k) {
                used -= (nums[left] == 0);
                left++;
            }
            maxLength = max(maxLength, (right - left + 1));
        }
        return maxLength;
    }
};