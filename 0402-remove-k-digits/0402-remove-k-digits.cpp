class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> maxHeap;
        if (num.size() <= k)
            return "0";
        for (auto ch : num) {
            while (!maxHeap.empty() && k > 0 && maxHeap.top() > ch) {
                maxHeap.pop();
                k--;
            }
            maxHeap.push(ch);
        }
        while (!maxHeap.empty() && k > 0) {
            maxHeap.pop();
            k--;
        }
        string ans = "";
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        while (ans.size()>0&&ans.back() == '0')
            ans.pop_back();

        if(ans.size()==0) return "0";
         reverse(ans.begin(),ans.end());

        return ans;
    }
};