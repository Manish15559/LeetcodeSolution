class Solution {
public:
bool check(int curr,vector<int>&candies,long long k){
    if(curr==0) return true;
    long long sum=0;
    for(auto it:candies) {
        sum+=(it/curr);

      
    }


    

    return k<=sum;
}
    int maximumCandies(vector<int>& candies, long long k) {

    int n=candies.size();
    int low=0;
    int high=1e7;

    while(high-low>1){
        int mid=(high+low)/2;

        if(check(mid,candies,k)==true) low=mid;
        else high=mid-1;

    }

    if(check(high,candies,k)==true) return high;
    else return low;

        
    }
};