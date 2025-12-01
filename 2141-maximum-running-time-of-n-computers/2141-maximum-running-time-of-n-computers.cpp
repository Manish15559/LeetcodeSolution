class Solution {
public:
    bool check(long long target,vector<int>&arr,int n){
        long long rem=0;
        long long curr=target;
        
        for(auto it:arr){
            if((rem+it)>=curr){
                curr-=rem;
                long long val=min((it-curr),(target-curr));
                rem=val;
                n--;
                curr=target;


            }
            else{
                curr-=(it+rem);
                rem=0;
            }

        }

        return n<=0;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end(),greater<int>());
        long long sum= accumulate(batteries.begin(),batteries.end(),(long long)0);
        long long low=0;
        long long high=sum;
        cout<<high<<endl;
        while(high-low>1){
            long long mid=(high+low)/2;
            if(check(mid,batteries,n)) low=mid;
            else high=mid-1;

        }

        if(check(high,batteries,n)) return high;
        return low;
        
    }
};