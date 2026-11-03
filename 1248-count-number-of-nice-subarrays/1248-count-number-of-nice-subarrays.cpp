class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int n=nums.size();
         int left=0;
         int count=0;
         int ans=0;
         for(int right=0;right<n;right++){
            if(nums[right]%2==1){
                count=0;
                k--;
            }
            while(k==0){
                count++;
                k+=nums[left]%2;
                left++;

            }
            ans+=count;
         }
         return ans;
    }
};