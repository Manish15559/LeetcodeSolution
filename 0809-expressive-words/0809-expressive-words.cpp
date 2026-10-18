class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<int, int>> arr;
        int count = 1;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                count++;
            else {
                arr.push_back({s[i - 1], count});
                count = 1;
            }
        }
        arr.push_back({s[n - 1], count});
        int ans = 0;
        for (auto word : words) {
            vector<pair<int, int>> arr1;
            int count = 1;
            int n = word.size();
            for (int i = 1; i < n; i++) {
                if (word[i] == word[i - 1])
                    count++;
                else {
                    arr1.push_back({word[i - 1], count});
                    count = 1;
                }
            }
            arr1.push_back({word[n - 1], count});

            if (arr.size() == arr1.size()) {
                bool flag = true;
                for (int i = 0; i < arr1.size(); i++) {
                    int diff = (arr[i].second - arr1[i].second);
                    if (!(arr[i].first == arr1[i].first &&
                          (diff == 0 ||  arr[i].second >= 3)&&diff>=0)) {
                        flag = false;
                        break;
                    }
                }
                ans += flag;
            }
        }
        return ans;
    }
};