class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return {};

        stack<int> minHeap;
        vector<int> visiblePeople(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (!minHeap.empty() && heights[minHeap.top()] < heights[i]) {
                minHeap.pop();
                count++;
            }
            if (!minHeap.empty())
                count++;
            visiblePeople[i] = count;

            minHeap.push(i);
        }
        return visiblePeople;
    }
};