class Solution {
public:
  
    vector<int> findCoins(vector<int>& numWays) {

        int n=numWays.size();
        vector<int>ways(n+1,0);
        vector<int>ans;
        ways[0]=1;
        for(int idx=1;idx<=n;idx++){
            if(ways[idx]==numWays[idx-1]) continue;
            ans.push_back(idx);
            for(int i=idx;i<=n;i++){
                ways[i]+=ways[i-idx];
            }
             if(ways[idx]!=numWays[idx-1]) return {};

        }

        return ans;
        
    }
};