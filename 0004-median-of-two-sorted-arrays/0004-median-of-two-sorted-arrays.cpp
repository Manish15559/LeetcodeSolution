class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;
        int n=n1+n2;
        int totalElementOnRight = (n1 + n2 + 1) / 2;

        while (low <= high) {
            int mid = (low + high) / 2;
            int secondMid = (totalElementOnRight - mid);
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid != n1)
                r1 = nums1[mid];
            if (secondMid != n2)
                r2 = nums2[secondMid];
            if ((mid ) > 0)
                l1 = nums1[mid - 1];
            if ((secondMid) > 0)
                l2 = nums2[secondMid - 1];
            cout<<mid<<" "<<secondMid<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;

            if (max(l1, l2) <= min(r1, r2)) {
                if (n % 2 == 0)
                    return (double)(min(r1, r2) + max(l1, l2)) / 2.0;
                else
                    return (double)max(l1, l2);
            }

                if (l1 > r2) {
                    high=mid-1;

                } else {
                    low = mid + 1;
                }
            }
            return -1;
        }
    };
