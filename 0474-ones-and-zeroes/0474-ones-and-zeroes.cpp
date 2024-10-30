class Solution {
public:
int helper(int idx,int n,int m,vector<int>&one,vector<int>&zero,vector<vector<vector<int>>>&dp){

    if(idx<0) return 0;
    if(dp[idx][n][m]!=-1) return dp[idx][n][m];


    //take it
    int take=0;
    if(n-one[idx]>=0&&m-zero[idx]>=0){
        take=1+helper(idx-1,n-one[idx],m-zero[idx],one,zero,dp);
    }
    int nottake=helper(idx-1,n,m,one,zero,dp);

    return dp[idx][n][m]=max(take,nottake);
    

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int>one,zero;
        int sz=strs.size();
        for(int idx=0;idx<sz;idx++){
            int cnt1=0; //storing cnt of one
            int cnt2=0; //storing cnt of zero;
            for(auto it:strs[idx]){
                if(it=='0') cnt2++;
                else cnt1++;
            }
            one.push_back(cnt1);
            zero.push_back(cnt2);
        }
 vector<vector<vector<int>>>dp(sz,vector<vector<int>>(n+1,vector<int>(m+1,0)));
        for(int idx=0;idx<sz;idx++){
            for(int curr_n=0;curr_n<=n;curr_n++){
                for(int curr_m=0;curr_m<=m;curr_m++){
                    //take it
                    int op1=0;
                    // cout<<idx<<" "<<curr_n<<" "<<curr_m<<endl;
                    if(curr_n>=one[idx]&&curr_m>=zero[idx]){
                        op1=(idx>0)?dp[idx-1][curr_n-one[idx]][curr_m-zero[idx]]:0;
                        op1+=1;
                    }
                    //    cout<<idx<<" "<<curr_n<<" "<<curr_m<<endl;
                    int op2=(idx>0)?dp[idx-1][curr_n][curr_m]:0;

                    dp[idx][curr_n][curr_m]=max(op1,op2);
                }
            }
        }

       

            int ans=dp[sz-1][n][m];
            return ans;
        }
        
    
};