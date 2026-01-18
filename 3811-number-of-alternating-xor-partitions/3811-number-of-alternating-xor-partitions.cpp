class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        long long cnt1=1;  //0
        long long cnt2=0;  //target1  
        long long cnt3=0;  //target1^target2
        long long cnt4=0;  //target2
        int mod=1e9+7;
        int last=0;
        int curr=0;
        for(auto it:nums){
            curr^=it;
            int c1=0;
            int c2=0;
            int c3=0;
            int c4=0;
            if(curr==0) c1=cnt4;
            if(curr==target1) c2=cnt1;
            if(curr==(target1^target2)) c3=cnt2;
            if(curr==(target2)) c4=cnt3;
            last=(c1+c2+c3+c4)%mod;
            cnt1+=c1%mod;
            cnt2+=c2%mod;
            cnt3+=c3%mod;
            cnt4+=c4%mod;
            cnt1%=mod;
            cnt2%=mod;
            cnt3%=mod;
            cnt4%=mod;
           
            
        }
        return last;
    }
};