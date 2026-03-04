class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left=0; //point to first zero value;
        int n=nums.size();
        for(int right=0;right<n;right++){
            while(left<n&&nums[left]!=0) left++;
            if(nums[right]!=0&&left<right) swap(nums[left],nums[right]);

        }
        
        
    }
};