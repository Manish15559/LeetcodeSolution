class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int N=1e5+10;
        vector<int>cntOfDivisors(N,0);
        vector<int>sumOfDivisors(N,0);
        for(int i=1;i<N;i++){
            for(int j=i;j<N;j+=i) {
                cntOfDivisors[j]++;
                sumOfDivisors[j]+=i;
            }
        }
        int ans=0;
        for(auto it:nums){
            if(cntOfDivisors[it]==4) ans+=sumOfDivisors[it];

        }

        return ans;

        
    }
};