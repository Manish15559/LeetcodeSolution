class Solution {
public:
   
     double find( double range,vector<vector<int>>&squares){
         double ans=0;
        for(auto &it:squares){
            if(( double)it[1]>=range) continue;
            else if(( double)(it[1]+it[2])<=range) ans+=(( double)it[2]*it[2]);
            else{
                 double length = (range-it[1]);
                ans+=(length*it[2]);
            }
        }
        return ans;

    }
    double separateSquares(vector<vector<int>>& squares) {
      
         double tot=0;
          double low=1e9+10;
         double high=-1;
        for(auto &it:squares) {
            tot+=((double)it[2]*it[2]);
            low=min(low,(double)it[1]);
            high=max(high,(double)(it[1]+it[2]));
        }
        
        while(high-low>1e-5){
            double mid=(low+high)/2;
            double val= find(mid,squares);
            if(tot>2*val) low=mid;
            else high=mid;
           

        }

        return high;


        
    }
};