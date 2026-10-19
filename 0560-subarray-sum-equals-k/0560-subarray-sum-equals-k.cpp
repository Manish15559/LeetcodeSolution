class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        int prefixSum = 0;
        prefixCount[prefixSum]++;
        int count = 0;
        for (auto num : nums) {
            prefixSum += num;

            if (prefixCount.find((prefixSum - k)) != prefixCount.end()) {
                count += prefixCount[(prefixSum - k)];
            }

            prefixCount[prefixSum]++;
        }
        return count;
    }
};