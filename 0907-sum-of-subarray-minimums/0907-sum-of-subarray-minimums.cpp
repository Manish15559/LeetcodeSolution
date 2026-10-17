class Solution {
public:
    vector<int> findNextSmallestElements(vector<int>& arr, int n) {
        vector<int> nextSmallestElement(n,n);
        stack<int> maxHeap;
        for (int i = n - 1; i >= 0; i--) {
            
            while (!maxHeap.empty() && arr[maxHeap.top()] > arr[i]) {
                maxHeap.pop();
            }
           
            if (maxHeap.empty())
                nextSmallestElement[i] = n;
            else
                nextSmallestElement[i] = maxHeap.top();

            maxHeap.push(i);
        }
        return nextSmallestElement;
    }
    vector<int> findPreviousSmallestElements(vector<int>& arr, int n) {
        vector<int> PreviousSmallestElement(n,-1);
        stack<int> maxHeap;
        for (int i = 0; i < n; i++) {
            while (!maxHeap.empty() && arr[maxHeap.top()] >= arr[i]) {
                maxHeap.pop();
            }
            if (maxHeap.empty())
                PreviousSmallestElement[i] = -1;
            else
                PreviousSmallestElement[i] = maxHeap.top();
            maxHeap.push(i);
        }
        return PreviousSmallestElement;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmallestElements = findNextSmallestElements(arr, n);
        vector<int> previousSmallestElements =
            findPreviousSmallestElements(arr, n);
        long long ans = 0;
         int mod=1e9+7;
        for (int i = 0; i < n; i++) {
           
            int left = i - previousSmallestElements[i];
            int right = nextSmallestElements[i] - i;
            long long val=(left*1ll*right)%mod;
            val=(val*arr[i])%mod;
            ans=(ans+val)%mod;
        }
       
        return ans % mod;
    }
};
