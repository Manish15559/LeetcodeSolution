class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1=0;
        int idx2=0;
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[idx1]>nums[i]) idx1=i;
            if(nums[idx2]<nums[i]) idx2=i;

        }

        int op1=max(idx1,idx2)+1;
        int op2=n-min(idx1,idx2);

        int op3=min(idx1,idx2)+1+(n-max(idx1,idx2));

        return min({op1,op2,op3});



        
    }
};