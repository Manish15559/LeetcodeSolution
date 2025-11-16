bool comp(vector<int>a,vector<int>b){
    if(a[0]==b[0]) return a[1]>=b[1];
    else return a[0]<b[0];
   }
class Solution {
public:
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int>arr;
        for(auto it:envelopes){
            int val=it[1];
            if(arr.empty()||arr.back()<val) {
                arr.push_back(val);
                continue;
            }
            int idx=lower_bound(arr.begin(),arr.end(),val)-arr.begin();
            // idx--;
           if(idx!=arr.size()) arr[idx]=val;
        }
        return arr.size();
        
    }
};