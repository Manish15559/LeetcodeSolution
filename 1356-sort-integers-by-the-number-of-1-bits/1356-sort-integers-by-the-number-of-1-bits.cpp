bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

class Solution {
public:
    int countBit(int n){
        int count=0;
        while(n>0){
            count+=(n%2);
            n/=2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>pair;
        for(auto it:arr) pair.push_back({countBit(it),it});

        sort(pair.begin(),pair.end(),compare);

        vector<int>ans;
        for(auto it:pair) ans.push_back(it.second);

        return ans;
        
    }
};