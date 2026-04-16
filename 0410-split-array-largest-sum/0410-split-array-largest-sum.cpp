class Solution {
public:
   bool check(long long mid,int k,vector<int>&nums){
    int cnt=1;
    long long sum=0;
    for(auto it:nums){
        if((sum+it)>mid){
            cnt++;
            sum=it;
        }
        else{
            sum+=it;
        }

    }
    // cout<<cnt<<endl;

    return cnt<=k;
   }


    int splitArray(vector<int>& nums, int k) {

        long long low=*max_element(nums.begin(),nums.end());
        long long high=0;
        for(auto it:nums) high+=it;

        while(high-low>1){
            long long mid=(low+high)/2;
            cout<<mid<<endl;
            if(check(mid,k,nums)) high=mid;
            else low=mid+1;
        }

        if(check(low,k,nums)) return low;
        return high;
        
    }
};