class Solution {
public:
     int sum=0;
     vector<int>cumulativeSum;
    Solution(vector<int>& w) {
        
       
        for(auto it:w){
            sum+=it;
            cumulativeSum.push_back(sum);
        }
        
    }
    
    int pickIndex() {
        
        int value = rand()%sum+1;

        int idx=lower_bound(cumulativeSum.begin(),cumulativeSum.end(),value)-cumulativeSum.begin();

        return idx;

        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */