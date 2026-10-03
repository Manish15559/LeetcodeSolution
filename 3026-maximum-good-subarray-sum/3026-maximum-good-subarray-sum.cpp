class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> sum;
        long long tot = 0;
        long long ans = -1e18;
        for (auto it : nums) {
            if (sum.find((it + k)) != sum.end()) {
                ans = max(ans, (it + tot - sum[(it + k)]));
            }
            if (sum.find((it - k)) != sum.end()) {
                ans = max(ans, (it + tot - sum[(it - k)]));
            }
            if (sum.find(it) != sum.end()) {
                sum[it] = min(sum[it], (tot));
            } else {
                sum[it] = tot;
            }
            tot += it;
        }
        if(ans==-1e18) return 0;
        return ans;
    }
};