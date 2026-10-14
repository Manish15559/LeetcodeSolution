class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        int mx = 0;
        for (int idx = 0; idx < word.size(); idx+=k) {
            string str = word.substr(idx, k);
            mp[str]++;
            mx = max(mp[str], mx);
        }

        return (((word.size()) / k) - mx);
    }
};