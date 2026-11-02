class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int min_value = *min_element(nums.begin(), nums.end());

        int sumRequired = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - min_value;
            sumRequired += diff;
        }

        return sumRequired;
    }
};