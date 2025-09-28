// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int low=1;
        int high=n;
        while(high-low>0){
            int mid= ((high-low)/2)+low;
            if(isBadVersion(mid)) high=mid;
            else low=mid+1;
        }
        if(isBadVersion(low)) return low;
        else return high;
        
    }
};