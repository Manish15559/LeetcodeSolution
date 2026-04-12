bool comp(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first)
        return x.second < y.second;
    return x.first > y.first;
}

class Solution {
public:
    long long binexp(long long x, long long y, int m) {
        if (y == 0)
            return 1;
        long long val = binexp(x, y / 2, m);
        if (y % 2 == 1)
            return (val * x * val) % m;
        else
            return (val * val) % m;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<pair<int, int>> arr;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums0[i] == 0) {
                count += nums1[i];

            } else {
                arr.push_back({nums1[i], nums0[i]});
            }
        }
        sort(arr.begin(), arr.end(), comp);
        long long ans = 0;
        int mod = 1e9 + 7;
        ans = binexp(2, count, mod) - 1;
        cout<<ans<<endl;
        for (int i = 0; i < arr.size(); i++) {
            // cout<<arr[i].first<<" "<<arr[i].second<<endl;

            long long val1 = binexp(2, arr[i].first, mod) - 1;
            long long val2 = binexp(2, arr[i].second, mod);
            long long val = (val1 * val2) % mod;
            ans*=binexp(2,(arr[i].first+arr[i].second),mod);
            ans%=mod;
            ans += val;
            ans %= mod;
        }

        return ans;
    }
};