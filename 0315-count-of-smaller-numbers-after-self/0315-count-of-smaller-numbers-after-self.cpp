class Solution {
public:
    void merge(int low, int mid, int high, vector<pair<int, int>>& arr,
               vector<int>& count) {
        int left = low;
        int right = mid + 1;
        vector<pair<int, int>> temp;
        while (left <= mid && right <= high) {
            if (arr[left].first <= arr[right].first) {
                temp.push_back(arr[left]);
                count[arr[left].second] += (right - (mid + 1));
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            count[arr[left].second] += (right - (mid + 1));
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int idx = low; idx <= high; idx++) {
            arr[idx] = temp[idx - low];
        }
    }

    void mergeSort(int low, int high, vector<pair<int, int>>& arr,
                   vector<int>& count) {
        if (low == high)
            return;
        int mid = (low + high) / 2;
        mergeSort(low, mid, arr, count);
        mergeSort(mid + 1, high, arr, count);

        merge(low, mid, high, arr, count);
    }

 vector<int> countSmaller(vector<int>& nums) {

    vector<pair<int, int>> arr;
    int n = nums.size();
    for (int i=0;i<n;i++) {
        arr.push_back({nums[i], i});
    }
    vector<int> count(n, 0);
    mergeSort(0, n - 1, arr, count);

    return count;
}
}
;