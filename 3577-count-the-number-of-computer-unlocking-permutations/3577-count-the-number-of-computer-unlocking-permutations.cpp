class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int rootComplexity=complexity[0];
        for(int i=1;i<complexity.size();i++){
            if(rootComplexity>=complexity[i]) return 0;
        }

        int mod=1e9+7;
        long long curr=1;
        for(int i=complexity.size()-1;i>=1;i--){
            curr=((curr%mod)*(i%mod))%mod;

        }
        return curr;
        
    }
};