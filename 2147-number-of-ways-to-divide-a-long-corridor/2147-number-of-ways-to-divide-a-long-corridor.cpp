class Solution {
public:
    int numberOfWays(string corridor) {

        int previous=-1;
        long long count=1;
        int mod=1e9+7;
        int seats=0;

        for(int idx=0;idx<corridor.size();idx++){
            if(corridor[idx]=='S'){
                seats+=1;
                if(seats==2){
                    seats=0;
                    previous=idx;
                }
            
            else if(seats==1&&previous!=-1){
                count*=(idx-previous);
                count%=mod;
            }
        }
        }

        if(seats==1||previous==-1) return 0;
        return count;
        
    }
};