class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

       
        for(int i=0;i<n;i++){
         int x=nums[i];
         while(x>=1&&x<=n&&x!=(i+1)&&nums[x-1]!=x){
            swap(nums[i],nums[x-1]);
            x=nums[i];

         }
            
        }
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<" ";
            if((i+1)!=nums[i]) return (i+1);
        }

        return (n+1);
        
    }
};