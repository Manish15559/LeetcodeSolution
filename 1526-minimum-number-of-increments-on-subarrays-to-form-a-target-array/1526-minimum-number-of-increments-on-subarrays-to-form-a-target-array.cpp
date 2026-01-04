class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        int ans=0;
        int curr=0;
        for(auto it:target){
            if(curr<it){
                ans+=(it-curr);
                curr=it;
            }
            else curr=it;
        }
        return ans;
        
    }
};