class Solution {
public:
    string longest(int l,int r,string &s,int n){
        while(l>0&&r<(n-1)&&s[l-1]==s[r+1]){
            l--;
            r++;
        }

        return s.substr(l,(r-l+1));
    }
    string longestPalindrome(string s) {
    int n=s.size();
    // int ans=1;
    string ans;

    for(int i=0;i<n;i++){
        if(i>0&&s[i]==s[i-1]) {
            string str =longest(i-1,i,s,n);
            if(ans.size()<str.size()) ans=str;
        }
         string str =longest(i,i,s,n);
            if(ans.size()<str.size()) ans=str;
       

    }
    return ans;
        
    }
};