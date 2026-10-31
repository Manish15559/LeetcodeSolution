class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0;
        int count = ((n + 1)) / 2;
        int high = min(count, n1);
        while (low <= high) {
            int mid = (low + high) / 2;
            int leftIdx1 = (mid - 1) >= 0 ? nums1[mid - 1] : INT_MIN;
            int rightIdx1 = (mid < n1) ? nums1[mid] : INT_MAX;
            int leftIdx2 =
                (count - mid - 1) >= 0 ? nums2[(count - mid - 1)] : INT_MIN;
            int rightIdx2 = (count - mid) < n2 ? nums2[count - mid] : INT_MAX;

            if (leftIdx1 <= rightIdx2 && leftIdx2 <= rightIdx1) {
                if (n % 2) {
                    return (1.0 * max(leftIdx1, leftIdx2));

                } else
                    return (1.0 * (max(leftIdx1, leftIdx2) +
                                   min(rightIdx1, rightIdx2))) /
                           2;
            }

            if (leftIdx1 > rightIdx2)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};