class Solution {
public:
bool check(long long value,vector<int>&ranks,long long cars){
    for(auto it:ranks){
        long long x=value/it;
       
        cars-=(long long)sqrt(x);
        // cout<<cars<<endl;
    }
    return cars<=0;
}
    long long repairCars(vector<int>& ranks, int cars) {
    long long low=0;
    long long high=(long long)1e15;
    // cout<<check(10,ranks,cars);
    // return low;

    while(high-low>1){
        long long mid=(low+high)/2;
        if(check(mid,ranks,cars)==true) high=mid;
        else low=mid+1;
    }
    if(check(low,ranks,cars)) return low;
    return high;
        
    }
};