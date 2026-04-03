class Solution {
public:
    void find(int idx, int curr, int limit, vector<int>& nums,
              vector<int>& arr) {
        if (idx == limit) {
            arr.push_back(curr);
            return;
        }
        find(idx + 1, curr + nums[idx], limit, nums, arr);
        find(idx + 1, curr, limit, nums, arr);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;
        vector<int> firstHalf, secondHalf;
        find(0, 0, mid, nums, firstHalf);
        find(mid, 0, n, nums, secondHalf);
        sort(firstHalf.begin(), firstHalf.end());
        int ans = 1e9;
        for (auto it : secondHalf) {
            int val = goal - it;
            int idx = upper_bound(firstHalf.begin(), firstHalf.end(), val) -
                      firstHalf.begin();
                    
            if (idx != firstHalf.size())
                ans = min(ans, abs(val - firstHalf[idx]));
            if(idx>0) ans = min(ans, abs(val - firstHalf[idx - 1]));
        }

        return ans;
    }
};