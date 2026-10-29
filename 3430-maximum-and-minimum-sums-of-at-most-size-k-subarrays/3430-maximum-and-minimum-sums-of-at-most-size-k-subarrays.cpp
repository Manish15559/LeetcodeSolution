class Solution {
public:
    vector<int> findNge(vector<int>& nums, int k, int n) {
        deque<int> maxHeap;
        vector<int> ans(n);
        // 1 2 3       right=3    2
        for (int idx = n - 1; idx >= 0; idx--) {
            int right = min(n, (idx + k));
            while (!maxHeap.empty() && right <= maxHeap.front())
                maxHeap.pop_front();
            while (!maxHeap.empty() && nums[maxHeap.back()] <= nums[idx])
                maxHeap.pop_back();
            if (maxHeap.empty())
                ans[idx] = right;
            else
                ans[idx] = maxHeap.back();
            maxHeap.push_back(idx);
        }
      
        return ans;
    }
    vector<int> findPge(vector<int>& nums, int k, int n) {
        deque<int> maxHeap;
        vector<int> ans(n);
        for (int idx = 0; idx < n; idx++) {
            int left = max(-1, (idx - k));
            while (!maxHeap.empty() && left >= maxHeap.front())
                maxHeap.pop_front();
            while (!maxHeap.empty() && nums[maxHeap.back()] < nums[idx])
                maxHeap.pop_back();
            if (maxHeap.empty())
                ans[idx] = left;
            else
                ans[idx] = maxHeap.back();
            maxHeap.push_back(idx);
        }
        return ans;
    }
    vector<int> findNse(vector<int>& nums, int k, int n) {
        deque<int> minHeap;
        vector<int> ans(n);
        for (int idx = n - 1; idx >= 0; idx--) {
            int right = min(n, (idx + k));
            while (!minHeap.empty() && right <= minHeap.front())
                minHeap.pop_front();
            while (!minHeap.empty() && nums[minHeap.back()] >= nums[idx])
                minHeap.pop_back();
            if (minHeap.empty())
                ans[idx] = right;
            else
                ans[idx] = minHeap.back();
            minHeap.push_back(idx);
        }
        return ans;
    }
    vector<int> findPse(vector<int>& nums, int k, int n) {
        deque<int> minHeap;
        vector<int> ans(n);
        for (int idx = 0; idx < n; idx++) {
            int left = max(-1, (idx - k));
            while (!minHeap.empty() && left >= minHeap.front())
                minHeap.pop_front();
            while (!minHeap.empty() && nums[minHeap.back()] > nums[idx])
                minHeap.pop_back();
            if (minHeap.empty())
                ans[idx] = left;
            else
                ans[idx] = minHeap.back();
            minHeap.push_back(idx);
        }
        return ans;
    }
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nse = findNse(nums, k, n);
        vector<int> pse = findPse(nums, k, n);
        vector<int> nge = findNge(nums, k, n);
        vector<int> pge = findPge(nums, k, n);
        long long ans=0;
        for(int idx=0;idx<n;idx++){
            int left1=idx-pse[idx];
            int right1=nse[idx]-idx;
            int left2=idx-pge[idx];
            int right2=nge[idx]-idx;
            ans+=(left1*1ll*right1*1ll*nums[idx]);
            if((left1+right1-1)>k){
                int val=left1+right1-k-1;
                ans-=((val)*1ll*(val+1)*1ll*nums[idx])/2;
            }
            ans+=(left2*1ll*right2*1ll*nums[idx]);
            if((left2+right2-1)>k){
                int val=left2+right2-k-1;
                ans-=((val)*1ll*(val+1)*1ll*nums[idx])/2;
            }
        }
        return ans;
    }
};