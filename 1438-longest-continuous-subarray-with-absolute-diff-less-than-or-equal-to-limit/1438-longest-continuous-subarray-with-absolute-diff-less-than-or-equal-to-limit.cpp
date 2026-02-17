class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int>st;
        int left=0;
        int ans=1;
        for(int right=0;right<n;right++){
            st.insert(nums[right]);

            while(abs(*st.rbegin()-*st.begin())>limit) {
                st.erase(st.find(nums[left]));
                left++;
            }
            ans=max(ans,(right-left+1));

        }
        return ans;
        
    }
};