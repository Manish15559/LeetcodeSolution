class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n = nums.size() / 3;
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; i++) {
            maxHeap.push(nums[i]);
        }
        vector<long long> maxArr(n, 0);

        for (int i = n; i < 2 * n; i++) {
            maxHeap.push(nums[i]);
            if (i == n)
                maxArr[i - n] = maxHeap.top();
            else
                maxArr[i - n] = (maxArr[i - n - 1] + maxHeap.top());
            maxHeap.pop();
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 3 * n - 1; i >= 2 * n; i--) {
            minHeap.push(nums[i]);
        }

        vector<long long> minArr(n, 0);

        for (int i = 2 * n - 1; i >= n; i--) {
            minHeap.push(nums[i]);
            if (i == (2 * n - 1))
                minArr[i - n] = minHeap.top();
            else
                minArr[i - n] = (minArr[i - n + 1] + minHeap.top());
            minHeap.pop();
        }

        vector<long long> pref(3 * n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < 3 * n; i++) {
            pref[i] = (pref[i - 1] + nums[i]);
        }

        long long ans = pref[n - 1] - (pref[3 * n - 1] - pref[2 * n - 1]);
        for (int i = -1; i < n; i++) {
            long long first;
            if (i == -1)
                first = pref[n + i];
            else
                first = pref[n + i] - maxArr[i];
            long long second;
            if (i < (n - 1))
                second = (pref[3 * n - 1] - pref[n + i] - minArr[i + 1]);
            else
                second = pref[3 * n - 1] - pref[n + i];
            ans = min(ans, (first - second));
        }

        return ans;
    }
};