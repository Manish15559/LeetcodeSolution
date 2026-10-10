class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {

        int n = nums1.size();
        vector<int> bucket(100001, 0);
        int mx = 0;
        int k = k1 + k2;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            bucket[diff]++;
            mx = max(mx, diff);
        }
        for (int i = mx; i > 0 && k > 0; i--) {
            long long used = min(k, bucket[i]);
            bucket[i] -= used;
            bucket[i - 1] += used;
            k -= used;
            if(k==0){
                mx=i;
                break;
            }
        }

        long long ans = 0;
        for (int i = 0; i <= mx; i++)
            ans += (i * 1ll * i * bucket[i]);

        return ans;
    }
};