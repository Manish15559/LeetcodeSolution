class Solution {
public:
    long long countDistinct(long long n) {
        long long ans=0;
        string s= to_string(n);
        int sz=s.size();
        vector<long long>pow(sz,1);
        for(int i=1;i<sz;i++) pow[i]=(9*pow[i-1]);
        // int ans=0;
        for(int i=1;i<sz;i++) ans+=pow[i];

        bool f=true;
        for(int idx=0;idx<sz;idx++){
            int val=s[idx]-'0';
            if(val==0){
                f=false;
                break;
            }
            else{
                ans+=(val-1)*pow[sz-1-idx];
            }

        }

        return (ans+(f));
   
        
    }
};