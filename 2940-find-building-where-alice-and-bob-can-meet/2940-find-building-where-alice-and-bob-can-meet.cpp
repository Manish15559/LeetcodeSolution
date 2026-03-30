bool comp(vector<int>& a, vector<int>& b) { return a[1] > b[1]; }

class Solution {
public:
    int find(int val, vector<int>& arr, vector<int>& heights) {
        int low = 0;
        int high = arr.size() - 1;

        while ((high - low) > 1) {
            int mid = (high + low) / 2;
            if (heights[arr[mid]] > val)
                low = mid;
            else
                high = mid - 1;
        }
        if (heights[arr[high]] > val)
            return arr[high];
        return arr[low];
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        int m = queries.size();
        for (int i = 0; i < m; i++) {
            if (queries[i][0] > queries[i][1])
                swap(queries[i][0], queries[i][1]);
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), comp);
        int n = heights.size();
        vector<int> arr;
        int idx = 0;
        vector<int> ans(m, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (arr.size() > 0 && heights[arr.back()] <= heights[i])
                arr.pop_back();
            arr.push_back(i);

            while (idx < m && queries[idx][1] == i) {
                if(heights[queries[idx][0]]<heights[queries[idx][1]]||(queries[idx][0]==queries[idx][1])){
                   ans[queries[idx][2]] = queries[idx][1];
                   idx++;
                   continue;
                }
                int mx =
                    max(heights[queries[idx][0]], heights[queries[idx][1]]);
                if (mx >= heights[arr[0]])
                    ans[queries[idx][2]] = -1;
                else
                    ans[queries[idx][2]] = find(mx, arr, heights);
                idx++;
            }
        }

        return ans;
    }
};