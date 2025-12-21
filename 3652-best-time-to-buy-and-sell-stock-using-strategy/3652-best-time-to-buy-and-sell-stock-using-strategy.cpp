class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans=0;
        int n=prices.size();
        // vector<long long>pref(n+1,0);
        long long tot=0;

        for(int i=0;i<n;i++){

            tot+=(prices[i]*strategy[i]);
            
        }
        ans=tot;
        long long curr=0;
        long long left=0;
        long long right=0;
        
        for(int i=0;i<n;i++){
            curr+=prices[i];
            if((i-k/2)>=0) curr-=prices[(i-k/2)];
            right+=(prices[i]*strategy[i]);
            if(i>=k) left+=(prices[i-k]*strategy[i-k]);

            if(i>=(k-1)){
                long long leftHalf=left;
                long long rightHalf=tot-right;
                ans=max(ans,(curr+leftHalf+rightHalf));

            }
        }

        return ans;

        
    }
};