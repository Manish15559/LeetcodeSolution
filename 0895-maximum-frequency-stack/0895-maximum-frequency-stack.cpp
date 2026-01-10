class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>> st;
    int  mxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        st[freq[val]].push(val);
        mxFreq=max(mxFreq, freq[val]);
        
    }
    
    int pop() {
        int r=st[mxFreq].top();
        st[mxFreq].pop();
        freq[r]--;
        if(st[mxFreq].empty()) mxFreq--;
        return r;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */