class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid1 = n / 2;
        int mid2 = mid1 - 1;
        int median;
        if (n % 2 == 1)
            median = nums[mid1];
        else
            median = (nums[mid1] + nums[mid2]) / 2;
        int ans = 0;
        for (auto it : nums)
            ans += abs(it - median);

        return ans;
    }
};