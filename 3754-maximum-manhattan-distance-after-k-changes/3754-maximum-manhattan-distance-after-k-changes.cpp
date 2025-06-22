class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<int,int>cnt;

       int ans=0;

        for(auto it:s) 
        {cnt[it-'A']++;

        //north sount
        int mx1=max(cnt['N'-'A'],cnt['S'-'A']);
        int mi1=min(cnt['N'-'A'],cnt['S'-'A']);

        //east west
        int mx2=max(cnt['E'-'A'],cnt['W'-'A']);
        int mi2=min(cnt['E'-'A'],cnt['W'-'A']);

        int sum=mi1+mi2;
         if(sum>k) ans=max(ans, (mx1+mx2+(2*k)-sum));
         else  ans=max(ans,(mx1+mx2+sum));
        }

        return ans;
        
    }
};