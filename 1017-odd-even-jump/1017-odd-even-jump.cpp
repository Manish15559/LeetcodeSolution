class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0)); //0->odd //1->even;
        dp[n-1][0]=1;
        dp[n-1][1]=1;
        unordered_map<int,int>mp;
        mp[arr[n-1]]=(n-1);
        set<int>st;
        st.insert(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            //if i is odd jump;
            auto it= st.lower_bound(arr[i]);
            if(it==st.end()) dp[i][0]=0;
            else{
             int idx =mp[(*it)];
             dp[i][0]=dp[idx][1];

            }
            if(it!=st.end()&&(*it)==arr[i]){
                int idx =mp[(*it)];
                dp[i][1]=dp[idx][0];

            }
            else if(it!=st.begin()){
                it--;
                int idx =mp[(*it)];
                dp[i][1]=dp[idx][0];

            }
            else dp[i][1]=0;

            mp[arr[i]]=i;
            st.insert(arr[i]);


        }

        int ans=0;
        for(int i=0;i<n;i++) ans+=(dp[i][0]==1);

        return ans;
        
    }
};