class MinStack {
public:
    stack<long long> st;
    long long mini = -1;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;

        } else if (mini <= val) {
            st.push(val);

        } else {
            st.push(((long long)2 * val) - mini);
            mini = val;
        }
    }

    void pop() {
        long long val = st.top();
        st.pop();
        if (val < mini) {
            mini = 2 * mini - val;
        }
    }

    int top() {
        long long val = st.top();
        if (mini < val)
            return val;
        return mini;
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */