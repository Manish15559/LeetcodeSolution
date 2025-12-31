class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        bool haveZero=false;
        long long mul=1;
        for(auto it:nums){
            if(it==0&&!haveZero) haveZero=true;
            else mul*=it;
        }

        vector<int>ans;
        for(auto it:nums){
            if(haveZero) 
            if(it==0) ans.push_back(mul);
            else ans.push_back(0);
            else ans.push_back(mul/it);

        }

        return ans;
        
    }
};