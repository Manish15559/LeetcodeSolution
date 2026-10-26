class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        int n=piles.size()/3;
        sort(piles.begin(),piles.end());
        for(int idx=(3*n-2);idx>=n;idx-=2){
            ans+=piles[idx];

        }
        return ans;
        
    }
};