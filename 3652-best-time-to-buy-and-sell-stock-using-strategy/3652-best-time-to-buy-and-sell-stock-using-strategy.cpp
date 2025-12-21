class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans=0;
        int n=prices.size();
        vector<long long>pref(n+1,0);

        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+(prices[i-1]*strategy[i-1]);
            
        }
        ans=pref[n];
        long long curr=0;
        
        for(int i=0;i<n;i++){
            curr+=prices[i];
            if((i-k/2)>=0) curr-=prices[(i-k/2)];

            if(i>=(k-1)){
                long long leftHalf=pref[i-k+1];
                long long rightHalf=pref[n]-pref[i+1];
                ans=max(ans,(curr+leftHalf+rightHalf));

            }
        }

        return ans;

        
    }
};