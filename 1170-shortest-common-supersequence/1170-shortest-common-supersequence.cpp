class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(str1[idx1-1]==str2[idx2-1]){
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                }
                else{
                     dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);

                }
            }
        }
      
        string ans="";
        int i=n;
        int j=m;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
             
                 ans.push_back(str1[i-1]);
                i--;

            }
            else{
                  ans.push_back(str2[j-1]);
                j--;

            }
        }
        while(i>0){
              ans.push_back(str1[i-1]);
                i--;

        }
        while(j>0){
              ans.push_back(str2[j-1]);
                j--;

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};