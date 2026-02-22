class Solution {
public:
    long long dp[64][64][2];
    int popcount(long long n) {
        int count = 0;
        while (n > 0) {
            count += (n % 2);
            n /= 2;
        }
        return count;
    }
    vector<int> binRep(long long n) {
        vector<int> arr;
        while (n > 0) {
            arr.push_back(n % 2);
            n /= 2;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
    long long find(int idx, vector<int>&arr,int req,int tight){
        if(idx==arr.size()){
            return req==0;
        }
        long long tot=0;
        if(dp[idx][req][tight]!=-1) return dp[idx][req][tight];
        //take
        if((tight==0||arr[idx]==1)&&req>0){
            tot+=find(idx+1,arr,(req-1),tight);
        }
        int ntight=(tight)&(arr[idx]==0);
        tot+=find(idx+1,arr,req,ntight);
        // cout<<idx<<" "<<req<<" "<<tight<<endl;
        return dp[idx][req][tight]=tot;

    }
    long long solve(vector<int>&arr,int req){
        memset(dp,-1,sizeof(dp));
       
        // for(auto it:arr) cout<<it<<" ";
        long long ans = find(0,arr,req,1);
        // cout<<req<<" "<<ans<<endl;

        if(req==1) ans--;
        return ans;

    }
    long long popcountDepth(long long n, int k) {
        if(k==0) return 1;
        vector<int> dp(64, 0);

        for (int i = 2; i < 64; i++) {
            dp[i] = dp[popcount(i)] + 1;
            // cout<<dp[i]<<endl;
        }
        long long ans = 0;

        vector<int> arr = binRep(n);

        for(int i=1;i<64;i++){
            if(dp[i]==(k-1)) ans+=solve(arr,i);
        }

        return ans;




        return -1;
    }
};