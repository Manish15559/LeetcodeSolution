class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1); //where index i value denote the length of longest increasing dequrence whose last element is i

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]) dp1[i]=max(dp1[i],(1+dp1[j]));

            }
        }

        vector<int>dp2(n,1);
        //where index i value denote the length of longest decreasing dequrence whose first element is i

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]) dp2[i]=max(dp2[i],(1+dp2[j]));
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            if(dp1[i]==1||dp2[i]==1) continue;
            int totLen = dp1[i]+dp2[i]-1;
            cout<<totLen<<endl;
            ans=min(ans,(n-totLen));

        }
        return ans;
        
    }
};