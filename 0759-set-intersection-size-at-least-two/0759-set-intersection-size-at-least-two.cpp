bool comp(vector<int>&a,vector<int>&b){
    if(a[1]==b[1]) return a[0] < b[0];
    return a[1]<b[1];
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int prev2=-10;
        int prev1=-10;
        for(auto it:intervals){
            if(it[0]<=prev1&&prev1<=it[1]){
                if(it[0]<=prev2&&prev2<=it[1]) continue;
                else{
                    
                    prev2=prev1;
                    prev1=it[1];
                    if(prev2==prev1) prev2--;
                    cnt++;
                }
            }
            else{
                prev2=it[1]-1;
                prev1=it[1];
                cnt+=2;
            }

        }

        return cnt;

        
    }
};