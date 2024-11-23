class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
          slow=nums[slow];
            fast=nums[nums[fast]];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        int start=nums[0];
        while(start!=slow){
            slow=nums[slow];
            start=nums[start];
        }

        return start;
        
    }
};