class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {

        int idx=1;
        int n=weight.size();
        int ans=0;
        while(idx<n){
            if(weight[idx-1]>weight[idx]){
                ans++;
                idx+=2;
            }
            else{
                idx++;
            }
        }

        return ans;
        
    }
};