class Solution {
public:
bool isPalindrome(int l,int r,string &str){

   
    while(r>l){
        if(str[l++]!=str[r--]) return false;
    }
    return true;

}
int helper(int idx,string &s,vector<int>&dp){
    if(idx==s.size()) return 0;

    if(dp[idx]!=-1) return dp[idx];
 int mini=1e9;

    for(int right=idx;right<s.size();right++){
      
        if(isPalindrome(idx,right,s)==true){
            mini=min(mini,1+helper(right+1,s,dp));
        }
    }
   
return dp[idx]=mini;
}
    int minCut(string s) {

        vector<int>dp(s.size()+1,0);
        for(int idx=s.size()-1;idx>=0;idx--){
            int mini=1e9;
            for(int right=idx;right<s.size();right++){
                if(isPalindrome(idx,right,s)) mini=min(mini,1+dp[right+1]);
            }
            dp[idx]=mini;
        }
        

        return dp[0]-1;
    }
};