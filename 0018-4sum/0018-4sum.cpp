class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();

        for(int idx1=0;idx1<n;idx1++){
            if(idx1>0&&(nums[idx1]==nums[idx1-1])) continue;
            for(int idx2=idx1+1;idx2<n;idx2++){
                if(idx2>(idx1+1)&&(nums[idx2]==nums[idx2-1])) continue;
                long long value=(long long)target-nums[idx1]-nums[idx2];
                int left=idx2+1;
                int right=n-1;
                //  cout<<nums[idx1]<<" "<<nums[idx2]<<endl;
                while(left<right){
                    long long sum=nums[left]+nums[right];
                    if(sum==value){
                    while(left<right&&nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right-1]){
                        right--;
                    }
                   
                        ans.push_back({nums[idx1],nums[idx2],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum>value) right--;
                    else left++;
                }

            }
        }

        return ans;

        
    }
};