class Solution {
public:
    bool check(long long mini,vector<long long>&cities,int r,int k,int n){
        vector<int>arr(n+1,0);
        int extra=0;
        for(int i=0;i<n;i++){
            extra-=arr[i];
            long long val=extra+cities[i];
            if(val>=mini) continue;
            long long req= mini-val;
            if(req>k) return false;
            int range=i+(2*r)+1;
            range=min(n,range);
            arr[range]+=req;
            extra+=req;
            k-=req;

        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {

        int n=stations.size();
        vector<long long>cities(n+1,0);

        for(int i=0;i<n;i++){
            int left=max(0,(i-r));
            int right=min(n,(i+r+1));
            cities[left]+=stations[i];
            cities[right]-=stations[i];
        }

        for(int i=1;i<n;i++){
            cities[i]+=cities[i-1];
        }

        long long low=0;
        long long high=1e11;

        while(high-low>1){
            long long mid=(high+low)/2;
            if(check(mid,cities,r,k,n)) low=mid;
            else high=mid-1;
        }

        if(check(high,cities,r,k,n)) return high;
        else return low;
        
    }
};