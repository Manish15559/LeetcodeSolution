class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(auto ch:n) mx=max(mx,(ch-'0'));

        return mx;
        
    }
};