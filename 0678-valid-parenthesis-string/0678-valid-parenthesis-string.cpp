class Solution {
public:
    bool helper(int idx,int count,string &s){
        if(count<0) return 0;
        
        if(idx<0){
            if(count==0) return true;
            else return false;
        }
        if(s[idx]==')') return helper(idx-1,(count+1),s);
        else if(s[idx]=='(') return helper(idx-1,(count-1),s);
        else return (helper(idx-1,count-1,s)||helper(idx-1,count,s)||helper(idx-1,count+1,s));
     }
    bool checkValidString(string s) {
        int n=s.size();
        return helper(n-1,0,s);



        
    }
};