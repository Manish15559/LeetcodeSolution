class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
      
        int tottime=0;
        int n=startTime.size();
        for(int i=0;i<k-1;i++){
            tottime+=(endTime[i]-startTime[i]);
        }
        int ans=0;
        int left=0;
        for(int i=k-1;i<n;i++){
            tottime+=(endTime[i]-startTime[i]);
            int right=((i+1)==n)?eventTime:startTime[i+1];
            int time=right-left;
            ans=max(ans,(time-tottime));
            tottime-=(endTime[i-(k-1)]-startTime[i-(k-1)]);
            left=endTime[i-(k-1)];


        }
        return ans;
        
        
    }
};