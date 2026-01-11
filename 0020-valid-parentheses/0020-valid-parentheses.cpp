class Solution {
public:
    bool isMatch(char ch1, char ch2) {
        if (ch1 == '[' && ch2 == ']')
            return true;
        if (ch1 == '{' && ch2 == '}')
            return true;
        if (ch1 == '(' && ch2 == ')')
            return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;

        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);
            else {
                if (!st.empty() && isMatch(st.top(), it))
                    st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};