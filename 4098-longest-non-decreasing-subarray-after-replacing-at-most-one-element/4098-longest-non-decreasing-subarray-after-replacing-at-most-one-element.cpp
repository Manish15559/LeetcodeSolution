class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
       vector<int>left(n,0),right(n,0);
       left[0]=1;
       for(int i=1;i<n;i++){
        if(nums[i-1]<=nums[i]) left[i]=1+left[i-1];
        else left[i]=1;
       }
       right[n-1]=1;
       for(int i=n-2;i>=0;i--){
        if(nums[i]<=nums[i+1]) right[i]=1+right[i+1];
        else right[i]=1;
       }
       int ans=min(n,(*max_element(left.begin(),left.end())+1));
       for(int i=1;i<n-1;i++){
        if(nums[i-1]<=nums[i+1]) ans=max(ans,(1+left[i-1]+right[i+1]));
       }
       return ans;
    
   

    }
};