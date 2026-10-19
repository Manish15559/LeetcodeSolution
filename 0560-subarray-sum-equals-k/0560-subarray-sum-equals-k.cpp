class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        int sum = 0;
        sumCount[sum]++;
        int tot = 0;
        for (auto num : nums) {
            sum += num;
            tot += sumCount[(sum - k)];
            sumCount[sum]++;
        }
        return tot;
    }
};