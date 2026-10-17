class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> maxHeap;
        int n = heights.size();
        int maxWidth = 0;
        for (int idx = 0; idx <= n; idx++) {
            while (!maxHeap.empty() &&
                   (idx == n || heights[maxHeap.top()] > heights[idx])) {
                int val = maxHeap.top();
                maxHeap.pop();
                int left = (maxHeap.empty()) ? -1 : maxHeap.top();
                int right = idx;
                int width = (right - left - 1) * heights[val];
                maxWidth = max(width, maxWidth);
            }
            maxHeap.push(idx);
        }
        return maxWidth;
    }
};
