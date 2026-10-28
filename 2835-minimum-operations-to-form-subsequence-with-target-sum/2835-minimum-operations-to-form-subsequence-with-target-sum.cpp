class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> used(32, 0);
        for (int bit = 0; bit <= 31; bit++) {
            if ((target >> bit) & 1) {
                used[bit]--;
            }
        }
     
        for (auto num : nums) {
            int bit = log2(num);
            used[bit]++;
        }
        int carry=0;
        int step=0;
        for(int i=0;i<=31;i++){
            if(carry<0) step++;
            used[i]+=carry;
            if(used[i]>=0) carry=used[i]/2;
            else if(used[i]<0){
                carry=-1;
            }
        }
        if(carry<0) return -1;
        return step;
        
    }
};