class Solution {
public:

    bool check(long long k,vector<int>&piles,int h){
        long long timeRequired=0;

        for(auto pile:piles) timeRequired+=((pile/k)+(pile%k!=0));
        return timeRequired<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0;
        for(auto pile:piles) sum+=pile;
        long long low=1;
        long long high=sum;

        while(low<high){
            long long mid= ((high-low)/2)+low;
            if(check(mid,piles,h)) high=mid;
            else low=mid+1;
        }

        return high;

        
    }
};