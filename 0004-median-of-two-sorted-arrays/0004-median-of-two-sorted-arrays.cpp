class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        int leftMid = -1;
        int rightMid = -1;
        int n = n1 + n2;
        int count=0;
        while (idx1 < n1 && idx2 < n2) {
            if (nums1[idx1] < nums2[idx2]) {

                if (count == ((n / 2) - 1))
                    leftMid = nums1[idx1];
                if (count == (n / 2))
                    rightMid = nums1[idx1];
                idx1++;
                count++;

            } else {
                if (count == ((n / 2) - 1))
                    leftMid = nums2[idx2];
                if (count == (n / 2))
                    rightMid = nums2[idx2];
                idx2++;
                count++;
            }
        }
        while (idx1 < n1) {
            if (count == ((n / 2) - 1))
                leftMid = nums1[idx1];
            if (count == (n / 2))
                rightMid = nums1[idx1];
            idx1++;
            count++;
        }
        while (idx2 < n2) {
            if (count == ((n / 2) - 1))
                leftMid = nums2[idx2];
            if (count == (n / 2))
                rightMid = nums2[idx2];
            idx2++;
            count++;
        }

        if (n % 2 == 0)
            return ((double)(leftMid + rightMid)) / 2;
        else
            return (double)rightMid;
    }
};
