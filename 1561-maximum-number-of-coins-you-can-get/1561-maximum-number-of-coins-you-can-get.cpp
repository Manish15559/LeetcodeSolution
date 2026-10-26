class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxi = *max_element(piles.begin(), piles.end());
        vector<int> count(maxi + 1, 0);
        for (auto pile : piles)
            count[pile]++;
        int n = piles.size()/3;
        int cnt = 3 * n;
        int curr = maxi;
        bool f = false;
        int ans=0;
        while (cnt > n && curr > 0) {
            int elements = min(count[curr], (cnt - n));
            cnt -= elements;
            if (elements % 2) {
                if (f == false)
                    ans += ((elements / 2) * curr);
                else
                    ans += (((elements + 1) / 2) * curr);
                f = !f;
            } else {
                ans += (elements / 2) * curr;
            }
            curr--;
        }
        return ans;
    }
};