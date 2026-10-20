// 1 3 5 7 1 2 3 4 5 2 4 6 5 6 7

    class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeNums;

        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < n1 && idx2 < n2) {
            if (nums1[idx1] < nums2[idx2]) {
                mergeNums.push_back(nums1[idx1]);
                idx1++;

            } else {
                mergeNums.push_back(nums2[idx2]);
                idx2++;
            }
        }
        while (idx1 < n1)
            mergeNums.push_back(nums1[idx1++]);
        while (idx2 < n2)
            mergeNums.push_back(nums2[idx2++]);
        int n=n1+n2;

        if ((n) % 2 == 0)

            return double(mergeNums[n / 2] + mergeNums[(n / 2) - 1]) / 2;

        else
            return (double)mergeNums[n / 2];
    }
};

// 0 1 2 3 4 5
