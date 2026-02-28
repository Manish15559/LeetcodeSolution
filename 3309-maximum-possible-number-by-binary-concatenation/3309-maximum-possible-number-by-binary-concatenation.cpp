class Solution {
public:
    int cal(int value, int curr) {
        int rightBit = 0;
        for (int i = 0; i < 30; i++) {
            if ((value >> i) & 1)
                rightBit = i;
        }
        for (int i = rightBit; i >= 0; i--) {
            curr = (curr * 2);
            if ((value >> i) & 1)
                curr++;
        }

        return curr;
    }
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 3; i++) {

            int curr = cal(nums[i], 0);
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;
                int curr1 = cal(nums[j], curr);
                for (int k = 0; k < 3; k++) {
                    if (j == k || k == i)
                        continue;
                    int curr2 = cal(nums[k], curr1);
                    ans = max(ans, curr2);
                }
            }
        }

        return ans;
    }
};