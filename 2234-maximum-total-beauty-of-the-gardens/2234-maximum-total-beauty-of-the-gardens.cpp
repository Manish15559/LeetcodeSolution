class Solution {
public:
    int search(int mid, int low, int high, vector<int>& arr) {
        if (mid <= arr[high])
            return high + 1;

        while ((high - low) > 1) {
            int m = (high + low) / 2;
            if (arr[m] >= mid)
                low = m + 1;
            else
                high = m;
        }
        if (arr[low] < mid)
            return low;
        else
            return high;
    }
    int find(int start, int end, vector<int>& flowers, vector<long long>& suff,
             long long rem, int high) {
        // cout << start << " " << end << endl;
        if (start > end || high == 0 || flowers[start] >=(high+1))
            return 0;

        int low = flowers[end];
        while (high - low > 1) {
            int mid = (low + high) / 2;
            int idx = search(mid, start, end, flowers);
            long long cost = ((end - idx + 1) * 1ll * mid) - suff[idx];
            if (cost <= rem)
                low = mid;
            else
                high = mid - 1;
        }
        int idx = search(high, start, end, flowers);
        long long cost = ((end - idx + 1) * 1ll * high) - suff[idx];
        if (cost <= rem)
            return high;
        return low;
    }
    long long maximumBeauty(vector<int>& flowers, long long newFlowers,
                            int target, int full, int partial) {

        int n = flowers.size();
        sort(flowers.begin(), flowers.end(), greater<int>());
        vector<long long> suff(n + 1, 0);
        suff[n - 1] = flowers[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = (suff[i + 1] + flowers[i]);
        }
        int val = find(0, n - 1, flowers, suff, newFlowers, (target - 1));
        long long ans = val * 1ll * partial;
       
        long long used = 0;
        for (int i = 0; i < n; i++) {
            int req = max(0, (target - flowers[i]));
            if ((used + req) > newFlowers)
                break;
            used += req;
            long long rem = newFlowers - used;
            int mini = find(i + 1, n - 1, flowers, suff, rem, (target - 1));
           
            ans = max(ans, (((i + 1) * 1ll * full) + (mini * 1ll * partial)));
        }
        return ans;
    }
};