class Solution {
public:
    vector<int> findNSE(vector<int>&nums,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int>&nums,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<int>nse= findNSE(nums,n);
        vector<int>pse= findPSE(nums,n);
        int ans=0;
        for(int i=0;i<n;i++){
            int len=nse[i]-pse[i]-1;
            if(nums[i]>(threshold/len)) return len;
        }

        return -1;
        
    }
};