class Bitset {
public:
    vector<int> bits;
    int len;
    int totOne;
    int flipCount;
    Bitset(int size) {
        bits.resize(size, 0);
        len = size;
        totOne = 0;
        flipCount = 0;
    }

    void fix(int idx) {
        int totFlip = bits[idx] + flipCount;
       
        if (totFlip % 2 == 0) {
            bits[idx]++;
            totOne++;
        }
    }

    void unfix(int idx) {
        int totFlip = bits[idx] + flipCount;
        totFlip %= 2;
        if (totFlip % 2 == 1) {
            bits[idx]++;
            totOne--;
        }
    }

    void flip() {
        flipCount = !flipCount;
        totOne = len - totOne;
    }

    bool all() { return totOne == len; }

    bool one() { return totOne > 0; }

    int count() { return totOne; }

    string toString() {
        string ans;
        for (auto it : bits) {
            int bit = (it + flipCount) % 2;
            ans.push_back(char('0' + bit));
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */