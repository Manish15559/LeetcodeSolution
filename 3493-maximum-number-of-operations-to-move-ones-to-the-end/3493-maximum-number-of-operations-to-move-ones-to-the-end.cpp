class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int cnt=0;
        vector<int>arr;
        for(auto it:s){
            if(it=='0'){
                if(cnt>0)  arr.push_back(cnt);
                cnt=0;
            }
            else cnt++;
        }
        int ans=0;
        int curr=0;
        for(auto it:arr){
            curr+=it;
            ans+=curr;
        }
        return ans;
        
    }
};