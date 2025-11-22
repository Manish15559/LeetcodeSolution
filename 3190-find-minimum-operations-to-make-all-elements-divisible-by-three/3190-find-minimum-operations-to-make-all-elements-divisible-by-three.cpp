class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(auto num:nums) cnt+=((num%3)!=0);

        return cnt;
        
    }
};