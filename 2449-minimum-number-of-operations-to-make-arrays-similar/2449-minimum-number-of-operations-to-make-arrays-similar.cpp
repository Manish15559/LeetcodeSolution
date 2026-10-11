class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> even1, odd1, even2, odd2;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                even1.push_back(nums[i]);
            else
                odd1.push_back(nums[i]);

            if (target[i] % 2 == 0)
                even2.push_back(target[i]);
            else
                odd2.push_back(target[i]);
        }
        long long cnt1 = 0;
        long long cnt2 = 0;
        for (int i = 0; i < odd1.size(); i++) {
            int diff = odd2[i] - odd1[i];
            if (diff > 0)
                cnt1 += diff;
            else
                cnt2 += diff;
        }

        for (int i = 0; i < even1.size(); i++) {
            int diff = even2[i] - even1[i];
            if (diff > 0)
                cnt1 += diff;
            else
                cnt2 += diff;
        }

        return cnt1 / 2;
    }
};