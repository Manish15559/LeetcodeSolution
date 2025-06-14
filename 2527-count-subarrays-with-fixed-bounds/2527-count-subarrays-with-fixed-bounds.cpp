class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long start=-1;
        long long maxi=-1;
        long long mini=-1;
        long long count=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<minK||nums[i]>maxK) {
                start=i;
                mini=-1;
                maxi=-1;
            }
            if(nums[i]==minK) mini=i;
            if(nums[i]==maxK) maxi=i;
            if(mini!=-1&&maxi!=-1) count+=min(mini,maxi)-start;
        }

        return count;
        
    }
};