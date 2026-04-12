bool comp(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first)
        return x.second < y.second;
    return x.first > y.first;
}

class Solution {
public:
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
        while (count--) {
            ans = (2 * ans) + 1;
            ans %= mod;
        }
        for (int i = 0; i < arr.size(); i++) {
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
            int val = arr[i].first;
            while (val--) {
                ans = (2 * ans) + 1;
                ans %= mod;
            }
            val = arr[i].second;
            while (val--) {
                ans = (2 * ans);
                ans %= mod;
            }
        }

        return ans;
    }
};