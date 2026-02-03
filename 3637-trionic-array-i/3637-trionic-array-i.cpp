class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool f=true;
        int cnt=1;
        int n=nums.size();
        if(nums[0]>=nums[1]) return false;
        for(int i=2;i<n;i++){
            if(f==true){
                if(nums[i-1]<nums[i]) continue;
                else if(nums[i-1]==nums[i]) return false;
                else{
                    f=false;
                    cnt++;
                }
            }
            else{
                if(nums[i-1]>nums[i]) continue;
                else if(nums[i-1]==nums[i]) return false;
                else{
                    f=true;
                    cnt++;
                }
            }

        }

        return cnt==3;

        
    }
};