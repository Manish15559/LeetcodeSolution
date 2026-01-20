class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int>ans;
        for(auto it:nums){
            if(it==2) {
                ans.push_back(-1);
                continue;
            }
           for(int i=1;i<=it;i++){
            if((i|(i+1))==it){
                ans.push_back(i);
                break;
            }
           }
            
        }
        return ans;
        
    }
};