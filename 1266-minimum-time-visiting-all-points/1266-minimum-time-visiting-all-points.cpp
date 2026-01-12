class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x=points[0][0];
        int y=points[0][1];
        int ans=0;
        for(auto it:points){
            int a=abs(it[0]-x);
            int b=abs(it[1]-y);
            ans+=min(a,b);
            ans+=abs(a-b);
            x=it[0];
            y=it[1];
        }
        return ans;
        
    }
};