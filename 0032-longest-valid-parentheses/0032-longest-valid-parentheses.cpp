class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>st;
        int n=s.size();
        int boundary=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                if(st.empty()) boundary=-1;
                else{
                    int left=st.top();
                    st.pop();
                    if(boundary==-1) boundary=left;
                    else boundary=min(boundary,left);
                    if(st.empty()||boundary>=st.top()) ans=max(ans,(i-boundary+1));
                    else ans=max(ans,(i-st.top()));
                }
            }
        }

        return ans;
        
    }
};