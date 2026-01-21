class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            if(it==2) ans.push_back(-1);
            else{
                int bit=0;
                while(((it>>bit)&1)==1) bit++;
                ans.push_back((it-(1<<(bit-1))));
            }
        }
        return ans;
        
    }
};