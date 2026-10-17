class Solution {
public:
    vector<int> maxElementsOnRight(vector<int>& heights, int n) {
        int rightMax = -1;
        vector<int> rightMaxElements(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            rightMaxElements[i] = rightMax;
            rightMax = max(rightMax, heights[i]);
        }
        return rightMaxElements;
    }

    vector<int> maxElementsOnLeft(vector<int>& heights, int n) {
        int leftMax = -1;
        vector<int> leftMaxElements(n, -1);

        for (int i = 0; i < n; i++) {
            leftMaxElements[i] = leftMax;
            leftMax = max(leftMax, heights[i]);
        }
        return leftMaxElements;
    }

    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> leftMaxElements = maxElementsOnLeft(height, n);
        vector<int> rightMaxElements = maxElementsOnRight(height, n);

        int totWater = 0;
        for (int i = 0; i < n; i++) {
            int maxHeight = min(leftMaxElements[i], rightMaxElements[i]);
            if (maxHeight > height[i])
                totWater += (maxHeight - height[i]);
        }
        return totWater;
    }
};
