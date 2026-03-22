class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int countOdd=0;
        int countEven=0;
        for(auto it:nums1){
            if(it%2==0) countEven++;
            else countOdd++;
        }
        //try even
        bool flag=true;
        for(auto it:nums1){
            if(it%2==0) continue;
            if(countOdd>=2) continue;
           flag=false;
           break;
        }
        if(flag) return true;
        for(auto it:nums1){
            if(it%2==1) continue;
            if(countOdd>=1) continue;
            return false;
        }
        return true;
        
    }
};