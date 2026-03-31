bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

class Solution {
public:
    int find(int val, vector<pair<int, int>>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while ((high - low) > 1) {
            int mid = (low + high) / 2;

            if (arr[mid].first < val)
                low = mid;
            else
                high = mid - 1;
        }

        if (arr[high].first < val)
            return arr[high].second;

        return arr[low].second;
    }
    int maxValue(vector<vector<int>>& events, int k) {

        int n = events.size();
        sort(events.begin(), events.end(), comp);

        vector<pair<int, int>> dp[k + 1];
        dp[0].push_back({0, 0});

        for (int i = 0; i < n; i++) {
            for (int num = 1; num <= k; num++) {
                if (dp[(num - 1)].size() == 0)
                    break;

                if (dp[(num - 1)][0].first >= events[i][0])
                    break;
                
               
                int take = find(events[i][0], dp[(num - 1)]) + events[i][2];
                int nottake =0;
                if(dp[num].size()>0) nottake = dp[(num)].back().second;

                dp[num].push_back({events[i][1], max(take, nottake)});
                //  cout<<i<<" "<<num<<" "<<max(take,nottake)<<endl;

            }
        }
        int mx=0;
        for(int i=1;i<=k;i++) {
            if(dp[i].size()==0) break;
            mx=max(mx,dp[i].back().second);
        }

        return mx;
    }
};