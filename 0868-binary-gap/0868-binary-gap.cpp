class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int cnt=0;
        bool flag=false;
        while(n>0){
            if(flag==false&&(n%2)==0) {
                 n/=2;
                continue;
            }
            else flag=true;
            if(n%2==1){
                ans=max(ans,cnt);
                cnt=1;
            }
            else{
                cnt++;
            }
             n/=2;
           
        }
        return ans;
        
    }
};