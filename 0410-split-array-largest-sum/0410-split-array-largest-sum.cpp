class Solution {
public:
    bool check(int mid, vector<int>& nums, int k) {
        int curr = 0;
        k--;
        for (auto it : nums) {
            if ((curr + it) > mid) {
                k--;
                curr = it;
            } else {
                curr += it;
            }
        }
     return (k >= 0);
            // return mid;
    }
    int splitArray(vector<int>& nums, int k) {
        int mini=0;
        for(auto it:nums) mini=max(mini,it);
        int low = mini;
        int high = 1e9;
        while ((high - low) > 1) {
            int mid = (low + high) / 2;
            if (check(mid, nums, k))
                high = mid;
            else
                low = mid + 1;
        }
        if (check(low, nums, k))
            return low;
        else
            return high;
    }
};