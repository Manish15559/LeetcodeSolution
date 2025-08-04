class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int end=max((landStartTime[i]+landDuration[i]),(waterStartTime[j]+waterDuration[j]));
                
                 end=max(end,(min(landStartTime[i],waterStartTime[j])+landDuration[i]+waterDuration[j]));
                
                ans=min(ans,end);
            }
        }

        return ans;
        
    }
};