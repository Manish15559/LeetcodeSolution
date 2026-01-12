class Solution {
public:
    void addMultiplier(stack<char>&st,string &ans){
        string curr;
        while(('a'<=st.top()&&st.top()<='z')){
            curr.push_back(st.top());
            st.pop();
        }
        reverse(curr.begin(),curr.end());
        st.pop();
        int mul=1;
        int val=0;
        while(!st.empty()&&'0'<=st.top()&&st.top()<='9'){
            val=val+(mul*(st.top()-'0'));
            mul=mul*10;
            st.pop();
        }
        string s="";
        while(val--){
            s.append(curr);
        }
        if(st.empty()) ans.append(s);
        else{
            for(auto it:s){
                st.push(it);
            }
        }
        return;


    }
    void helper(int idx,stack<char>&st,string&ans,string &s){
        if(s.size()==idx) return;
        if('a'<=s[idx]&&s[idx]<='z'){
            if(st.empty()) ans.push_back(s[idx]);
            else st.push(s[idx]);
        }
        else if('0'<=s[idx]&&s[idx]<='9') st.push(s[idx]);
        else if(s[idx]=='[') st.push(s[idx]);
        else{
            addMultiplier(st,ans);
        }
        helper((idx+1),st,ans,s);
    }

    string decodeString(string s) {
        stack<char>st;
        string ans="";

        for(int idx=0;idx<s.size();idx++){
            if('a'<=s[idx]&&s[idx]<='z'){
            if(st.empty()) ans.push_back(s[idx]);
            else st.push(s[idx]);
        }
        else if('0'<=s[idx]&&s[idx]<='9') st.push(s[idx]);
        else if(s[idx]=='[') st.push(s[idx]);
        else{
            addMultiplier(st,ans);
        }

        }
      

        return ans;
        
    }
};