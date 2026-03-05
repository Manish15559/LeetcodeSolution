class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int>maxHeap;
        int n=heights.size();
        int tot=0;
        for(int i=1;i<n;i++){
            if(heights[i-1]>=heights[i]) continue;
            int diff=(heights[i]-heights[i-1]);
            maxHeap.push(diff);
            tot+=diff;
            while(tot>bricks&&!maxHeap.empty()){
                tot-=maxHeap.top();
                maxHeap.pop();
                ladders--;
            }
            if(ladders<0) return (i-1);

        }
        return (n-1);
        
    }
};