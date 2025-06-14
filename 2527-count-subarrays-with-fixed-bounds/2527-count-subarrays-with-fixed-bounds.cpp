class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long start=-1;
        long long maxi=-1;
        long long mini=-1;
        long long count=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<minK||nums[i]>maxK) start=i;
            if(nums[i]==minK) mini=i;
            if(nums[i]==maxK) maxi=i;
            count+=max((long long)0,min(mini,maxi)-start);
        }

        return count;
        
    }
};