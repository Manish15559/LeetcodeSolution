class Solution {
public:
    

    int check(int val,vector<int>&arr,int p){

        int n=arr.size();

        int cnt=0;
        int i=1;
        while(i<n){
            int diff=arr[i]-arr[i-1];

            if(diff<=val) {
                cnt++;
                i+=2;
            }
            else{
                i++;
            }


        }

        return cnt>=p;

    }
    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(),nums.end());

        int lo=0;
        int hi=nums.back()-nums[0];

        while(hi-lo>1){
            int mid=(hi+lo)/2;
            if(check(mid,nums,p)) hi=mid;
            else lo=mid+1;
        }

        if(check(lo,nums,p)) return lo;
        return hi;
        
    }
};