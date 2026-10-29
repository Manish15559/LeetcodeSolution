class Solution {
public:
    void helper(int idx,int sum,int n,vector<int>&nums,vector<int>&result){
        if(idx==n){
            result.push_back(sum);
            return;
        }
        helper(idx+1,sum,n,nums,result);
        helper(idx+1,(sum+nums[idx]),n,nums,result);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int mid=(n+1)/2;
        vector<int>firstHalf;
        helper(0,0,mid,nums,firstHalf);        
        vector<int>rightHalf;
        helper(mid,0,n,nums,rightHalf);
        sort(rightHalf.begin(),rightHalf.end());
        int ans=1e9;
        for(auto it:firstHalf){
            int req=goal-it;
            int idx=upper_bound(rightHalf.begin(),rightHalf.end(),req)-rightHalf.begin();
            if(idx!=rightHalf.size()) ans=min(ans,abs((req-rightHalf[idx])));
            if(idx>0) ans=min(ans,abs((req-rightHalf[idx-1])));
        }
        return ans;


        
    }
};