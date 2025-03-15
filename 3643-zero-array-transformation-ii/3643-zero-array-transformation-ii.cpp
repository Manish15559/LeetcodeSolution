class Solution {
public:
bool check(vector<int>nums,vector<vector<int>>& queries,int idx){
    // cout<<idx<<endl;
    int n=nums.size();
    vector<int>sum(n+1,0);
    for(int i=0;i<idx;i++){
        sum[queries[i][0]]+=queries[i][2];
        sum[queries[i][1]+1]-=queries[i][2];
    }
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];

    }
    for(int i=0;i<n;i++){
        if(nums[i]>sum[i]) return false;
    }

    return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();
        int m=queries.size();
        if(check(nums,queries,m)==false) return -1;

        int low=0;
        int high=m;
        while(high-low>1){
            int mid=(low+high)/2;
            if(check(nums,queries,mid)) high=mid;
            else low=mid+1;
        } 

        if(check(nums,queries,low)) return low;
        return high;


        
    }
};