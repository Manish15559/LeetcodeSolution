class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>minHeap;
        int m=nums2.size();
        unordered_map<int,int>nextGreater;
        for(int idx=m-1;idx>=0;idx--){
            while(!minHeap.empty()&&minHeap.top()<nums2[idx]) {
                minHeap.pop();
            }
            if(minHeap.empty()) nextGreater[nums2[idx]]=-1;
            else nextGreater[nums2[idx]]=minHeap.top();
            minHeap.push(nums2[idx]);
        }
        vector<int>ans;
        for(auto num:nums1){
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};