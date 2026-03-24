class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>minHeap;
        int n=heights.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            int count=0;
            while(!minHeap.empty()&&heights[minHeap.top()]<heights[i]){
                count++;
               minHeap.pop();
            }
            if(!minHeap.empty()) count++;
            minHeap.push(i);
            ans[i]=count;
        }
        return ans;
        
    }
};