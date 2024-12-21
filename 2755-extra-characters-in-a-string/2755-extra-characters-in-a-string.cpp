class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        unordered_set<string>st;
        for(auto it:dictionary) st.insert(it);

        int n=s.size();
        vector<int>dp(n+1,0);
      
        for(int right=1;right<=n;right++){
            int mini=1e9;
            
            for(int left=right;left>=1;left--){
                  
                string str=s.substr((left-1),(right-left+1));

                if(st.find(str)!=st.end()) mini=min(dp[left-1],mini);
                else mini=min(mini,(dp[left-1]+(right-left+1)));
            }
            dp[right]=mini;
        }
        return dp[n];
    }
};