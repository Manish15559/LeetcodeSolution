class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        long long ans = 0;
        int mod = 1e9 + 7;

        stack<int> maxHeap;
        for (int i = 0; i <= n; i++) {
            while (!maxHeap.empty() &&
                   (i == n || arr[maxHeap.top()] >= arr[i])) {
                int idx = maxHeap.top();
                maxHeap.pop();
                int left = (maxHeap.empty()) ? -1 : maxHeap.top();
                int right = i;
                int leftHalf = idx - left;
                int rightHalf = right - idx;
                long long val = (leftHalf * 1ll * rightHalf) % mod;
                val = (val*arr[idx])%mod;
                val %= mod;
                ans += val % mod;
                ans%=mod;
            }
            maxHeap.push(i);
        }

        return ans;
    }
};
