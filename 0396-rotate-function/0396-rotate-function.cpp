class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int prev=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prev+=(i*nums[i]);
        }
        int ans=prev;
        for(int time=1;time<n;time++){
            int curr = prev +(sum-nums[n-time])-((n-1)*nums[n-time]);
            ans=max(ans,curr);
            prev=curr;
        }

        return ans;
        
    }
};