class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int cnt=0;
        vector<int>arr;
        int ans=0;
        char prev='0';
        for(auto it:s){
            if(it=='1'){
                cnt++;
               
            }
            else{
                if(prev!='0') ans+=cnt;
              
            }
            prev=it;

           
        }
       
        return ans;
        
    }
};