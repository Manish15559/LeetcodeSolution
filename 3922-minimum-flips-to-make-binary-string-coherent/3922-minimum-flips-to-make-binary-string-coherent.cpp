class Solution {
public:
    int minFlips(string s) {
        
        int count=0;
        for(auto it:s){
            count+=(it=='1');
        }
        int n=s.size();
        if(n==count) return 0;
        if(n>1&&s[0]=='1'&&s[n-1]=='1') return min((count-2),(n-count));
        return min((n-count),max(0,(count-1)));
    }
};