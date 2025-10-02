class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
    unordered_set<int>st(nums.begin(),nums.end());  //o(n)
    int longest=0;
    for(int num:st){//o(n+n)
        if(st.find(num-1)==st.end()){
            int length=1;
            while(st.find(num+length)!=st.end()) length++;
            longest=max(longest,length);
        }
    }
    return longest;
        
    }
};