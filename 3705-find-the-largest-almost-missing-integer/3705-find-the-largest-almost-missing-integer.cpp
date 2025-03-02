class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    int n=nums.size();

    int freq[51]={0};

   for(int left=0;left<n-k+1;left++){
    int right=left+k;
    unordered_set<int>st;
    for(int i=left;i<right;i++)  st.insert(nums[i]);
    for(auto it:st) freq[it]++;
   }

   int ans =-1;

   for(int i=0;i<51;i++) if(freq[i]==1) ans=max(ans,i);

   return ans;
    }
};