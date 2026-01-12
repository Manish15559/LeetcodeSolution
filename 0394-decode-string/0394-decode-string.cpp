class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt;
        stack<int> numSt;

        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');   // handle multi-digit numbers
            }
            else if (c == '[') {
                numSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = numSt.top(); numSt.pop();
                string prev = strSt.top(); strSt.pop();

                string temp = "";
                while (repeat--) temp += curr;

                curr = prev + temp;
            }
            else {
                curr.push_back(c);
            }
        }

        return curr;
    }
};
