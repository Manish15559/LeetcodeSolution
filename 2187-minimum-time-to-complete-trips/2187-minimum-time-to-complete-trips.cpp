class Solution {
public:
    bool check(long long currentTime,vector<int>&time,long long totalTrips){
        for(auto it:time){
            totalTrips-=(currentTime/it);
        }
        return totalTrips<=0;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int minValue=*min_element(time.begin(),time.end());
        long long low=1;
        long long high=minValue*1ll*totalTrips;
        while(high>low){
            long long mid=((high-low)/2)+low;
            cout<<mid<<endl;
            if(check(mid,time,totalTrips)) high=mid;
            else low=mid+1;



        }
        return low;
        
    }
};