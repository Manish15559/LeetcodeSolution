class Solution {
public:
    int zigZagArrays(int n, int l, int r) {

        vector<long long>increasing(r+1,1),decreasing(r+1,1);
        int mod=1e9+7;

        for(int i=2;i<=n;i++){
            vector<long long>curr1(r+1,0),curr2(r+1,0);
            long long totdecrease =0;
             long long totincrease=0;
            for(int val=l;val<=r;val++) totincrease=(totincrease%mod+increasing[val]%mod)%mod;
           
            for(int val=l;val<=r;val++){
                 
                 totincrease=(totincrease+mod-increasing[val])%mod;
                curr1[val]=totdecrease; //increase
                curr2[val]=totincrease; //decrese
                totdecrease=(totdecrease%mod+decreasing[val]%mod)%mod;
                
               
            }
            increasing=curr1;
            decreasing=curr2;

            // for(int i=l;i<=r;i++){
            //     cout<<curr1[i]<<" "<<curr2[i]<<endl;
            // }
            // cout<<endl;

        }

        long long ans=0;
        for(int i=0;i<=r;i++){
            ans+=(increasing[i]%mod+decreasing[i]%mod)%mod;
            ans%=mod;
        }

        return ans;
        
    }
};