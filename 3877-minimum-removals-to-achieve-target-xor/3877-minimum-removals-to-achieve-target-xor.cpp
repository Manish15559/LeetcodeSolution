class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        // return (1<<14);
        int n=(1<<15);
        vector<int>check(n,-1);
        check[0]=0;
        for(auto it:nums){
             vector<int>check1(n,-1);
             check1=check;
            //  check1[it]=1;
            for(int i=0;i<n;i++){
                if(check[i]!=-1){
                    // check1[i]=max(check1[i],check[i]);
                    check1[i^it]=max(check1[i^it],(1+check[i]));

                }
            }
            check=check1;

        } 
        int m=nums.size();

        return (check[target]==-1)?-1:(m-check[target]);
        
    }
};