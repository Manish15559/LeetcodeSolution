class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        vector<int> arr;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > k)
                arr.push_back(1);
            else if (nums[i] == k)
                arr.push_back(0);
            else
                arr.push_back(-1);
        }
        bool flag = true;
        unordered_map<int, int> mp1, mp2;
        mp1[0]++;
        long long ans = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += arr[i];
            if (flag == true) {
                ans += mp1[curr];
                ans += mp2[(curr - 1)];
            } else {
                ans += mp1[curr - 1];
                ans += mp2[curr];
            }
            if (flag == false)
                mp1[curr]++;
            else
                mp2[curr]++;
            flag = !flag;
        }
        return ans;
    }
};