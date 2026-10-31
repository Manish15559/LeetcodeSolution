class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int leftMid = -1;
        int rightMid = -1;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int idx1 = 0;
        int idx2 = 0;
        int idx = -1;
        while (idx1 < n1 && idx2 < n2 && idx < n / 2) {
            idx++;

            if (nums1[idx1] <= nums2[idx2]) {
                if (idx == (n / 2 - 1))
                    leftMid = nums1[idx1];
                if (idx == (n / 2))
                    rightMid = nums1[idx1];
                idx1++;
            } else {
                if (idx == (n / 2 - 1))
                    leftMid = nums2[idx2];
                if (idx == (n / 2))
                    rightMid = nums2[idx2];
                idx2++;
            }
        }

            while (idx1 < n1 && idx < n / 2) {
                idx++;
                if (idx == (n / 2 - 1))
                    leftMid = nums1[idx1];
                if (idx == (n / 2))
                    rightMid = nums1[idx1];
                idx1++;
            }
            while (idx2 < n2 && idx < n / 2) {
                idx++;
                if (idx == (n / 2 - 1))
                    leftMid = nums2[idx2];
                if (idx == (n / 2))
                    rightMid = nums2[idx2];
                idx2++;
            }
             
            if (n % 2 == 0)
                return (1.0 * (leftMid + rightMid)) / 2;
            return (1.0 * rightMid);
        
    }
};