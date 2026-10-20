class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        // for this question, for each element i will mark whther it have
        // different parity then the previous one
        int n = nums.size();
        vector<int> parity(n, 0); // parity with the previous;
        for (int i = 1; i < n; i++) {
            if ((nums[i] % 2) != (nums[i - 1] % 2))
                parity[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            parity[i] += parity[i - 1];
        }
        vector<bool> ans;
        
        for (auto query : queries) {
            int left = query[0];
            int right = query[1];
            if ((right - left) == (parity[right] - parity[left]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};