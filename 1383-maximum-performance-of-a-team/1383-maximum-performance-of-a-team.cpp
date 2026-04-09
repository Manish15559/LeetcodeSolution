class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({efficiency[i], speed[i]});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            minHeap.push(arr[i].second);
            sum += arr[i].second;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans, (sum * arr[i].first));
        }

        return ans % mod;
    }
};