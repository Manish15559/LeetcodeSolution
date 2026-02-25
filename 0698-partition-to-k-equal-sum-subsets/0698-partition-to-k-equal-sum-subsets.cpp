class Solution {
public:
    bool backtrack(int curr_sum, int bitmask, int idx, int k, int target,vector<int>&nums) {
        if (k == 0)
            return true;

        if (curr_sum == target)
            return backtrack(0, bitmask, 0, k - 1, target,nums);

        for (int j = idx; j < nums.size(); j++) {
            bool visited = (bitmask >> j) & 1;
            if(visited || (curr_sum+nums[j])> target) continue;

            if(backtrack(curr_sum+nums[j],(bitmask|(1<<j)),j+1,k,target,nums)==true) return true;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto it : nums)
            sum += it;
        if (sum % k != 0 || k > nums.size())
            return false;

        return backtrack(0, 0, 0, k, sum / k,nums);
    }
};