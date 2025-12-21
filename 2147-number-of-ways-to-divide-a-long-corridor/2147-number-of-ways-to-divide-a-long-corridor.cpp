class Solution {
public:
    int numberOfWays(string corridor) {

        vector<int>gap;
        int cnt=0;
        int flag=false;
        for(auto it:corridor){
            if(it=='S'){
                if(flag==false){
                    gap.push_back(cnt);
                    cnt=0;
                    flag=true;
                }
                else{
                    flag=false;
                }
            }
            else if(flag==false) cnt++;
        }
        gap.push_back(cnt);

        if(flag||gap.size()==1) return 0;

        long long ans=1;
        int mod=1e9+7;
        for(int i=1;i<gap.size()-1;i++){
            ans=(ans*(gap[i]+1))%mod;
        }

        return ans;
        
    }
};