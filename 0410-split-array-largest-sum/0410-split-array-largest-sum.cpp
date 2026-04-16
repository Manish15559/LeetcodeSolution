class Solution {
public:
    bool check1(long long mid, int k, vector<int>& nums) {
        int cnt = 1;
        long long sum = 0;
        for (auto it : nums) {
            if ((sum + it) > mid) {
                cnt++;
                sum = it;
            } else {
                sum += it;
            }
        }

        return cnt <= k;
    }

    bool check2(long long mid, int k, vector<int>& nums) {
        long long remaining = mid;
        int cnt = 1;
        for (auto it : nums) {
            if ((remaining - it) < 0) {
                cnt++;
                remaining = mid - it;

            } else {
                remaining -= it;
            }
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;
        for (auto it : nums)
            high += it;

        while (high - low > 1) {
            long long mid = (low + high) / 2;
            // cout<<mid<<endl;
            if (check2(mid, k, nums))
                high = mid;
            else
                low = mid + 1;
        }

        if (check2(low, k, nums))
            return low;
        return high;
    }
};