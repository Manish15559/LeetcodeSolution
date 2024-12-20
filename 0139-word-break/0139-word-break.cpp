class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st;
        for(auto str:wordDict) st.insert(str);
        vector<bool>dp(n+1,false);
        dp[0]=true;

        for(int right=1;right<=n;right++){
          
            for(int left=right;left>=1;left--){
                int len=right-left+1;
                string str=s.substr(left-1,len);
                if(st.find(str)!=st.end()&&dp[left-1]==true) {
                    dp[right]=true;
                    break;
                }
            }
        }

        return dp[n];
        
    }
};