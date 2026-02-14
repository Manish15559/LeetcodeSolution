class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int prev=0;
        int n=nums.size();
        //Whenever you get struck on these kinds of questions, say for example, it will take O(N) time in solving for one permutation or anything similar to this, and it looks like you have to do this for all N permutations which will make it an overall O(N^2), then 9 out of 10 times there will be a way to calculate the ans for the next permutation if you have previous in constant O(1) time (this is the same case here), or maybe it might take O(logN) time. Always remeber that when you can't come up with better solution then O(N^2).
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