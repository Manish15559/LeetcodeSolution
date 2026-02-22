class Solution {
public:
    int binaryDown(vector<int>& arr, int target) { // lower or equal closer
                                                   // value
        int low = 0;
        int high = arr.size() - 1;
        if (arr[low] > target)
            return -1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target)
                low = mid;
            else
                high = mid - 1;
        }
        if (arr[high] <= target)
            return arr[high];
        return arr[low];
    }
    int binaryUp(vector<int>& arr, int target) { // more or equal target value
        int low = 0;
        int high = arr.size() - 1;
        if (arr[low] < target)
            return -1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (arr[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        if (arr[low] >= target)
            return arr[low];
        return arr[high];
    }
    int binarySearch(vector<int>& arr, int target) {
        int smaller = binaryDown(arr, target);
        int larger = binaryUp(arr, target);
        if (smaller == -1)
            return larger;
        if (larger == -1)
            return smaller;

        return abs(target - larger) > abs(target - smaller) ? smaller : larger;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        vector<int> left[m + 1], right[m + 1];
        int sum=0;
        for(auto it:nums) sum+=it;

        for (int mask = 0; mask < (1 << m); mask++) {
            int sz = 0;
            int l = 0;
            int r = 0;
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    sz++;
                    l += nums[i];
                    r += nums[m + i];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        

        for (int i = 0; i <= m; i++)
            sort(right[i].begin(), right[i].end());
        int ans = 1e9;

        for (int sz = 0; sz <= m; sz++) {
            for (auto firstHalf : left[sz]) {
                int target = (sum / 2) - firstHalf;
                // cout<<sz<<" "<<firstHalf<<" "<<target<<endl;
                int secondHalf = binarySearch(right[m - sz], target);
                // cout<<secondHalf<<endl;
                ans = min(ans, abs(sum - 2*(firstHalf + secondHalf)));
            }
        }

        return ans;
    }
};