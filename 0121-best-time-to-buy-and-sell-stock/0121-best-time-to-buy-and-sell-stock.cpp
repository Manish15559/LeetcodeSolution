class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPriceSoFar=1e9;
        int maxProfit=0;  //max profit achievable so far
        for(auto price:prices){
            maxProfit=max(maxProfit,(price-minimumPriceSoFar));
            minimumPriceSoFar=min(minimumPriceSoFar,price);
        }
        return maxProfit;
        
    }
};