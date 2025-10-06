class Solution {
public:

static bool compare(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int helper(int currNum,unordered_map<int,int>&powers){
    if(currNum==1) return 0;
    if(powers.find(currNum)!=powers.end()) return powers[currNum];
    if(currNum%2==1) return powers[currNum]=1+helper((3*currNum+1),powers);
    else return powers[currNum]=1+helper(currNum/2,powers);
}
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int>powers;
        vector<pair<int,int>>arr;

        for(int currNum=lo;currNum<=hi;currNum++){  //o(hi-lo+1)*o(max(valueofinteger))
            if(powers.find(currNum)==powers.end()){
                helper(currNum,powers);
            }
            arr.push_back({powers[currNum],currNum});
           
            
        }

        sort(arr.begin(),arr.end(),compare);

        int ans=arr[k-1].second;

        return ans;


        
        
    }
};