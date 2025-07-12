class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>q;
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
           if((i-k)==q.front()) q.pop_front();
           while(!q.empty()&&nums[q.back()]<=nums[i]) q.pop_back();
           q.push_back(i);
           
           if(i>=(k-1)) arr.push_back(nums[q.front()]);
        }
        return arr;
        
    }
};