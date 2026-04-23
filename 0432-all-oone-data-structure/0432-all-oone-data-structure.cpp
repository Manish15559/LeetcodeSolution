class AllOne {
public:
    map<int, set<string>> mp1;
    unordered_map<string, int> mp2;
    AllOne() {}

    void inc(string key) {
        if (mp2.find(key) == mp2.end()) {
            mp2[key] = 1;
            mp1[1].insert(key);
        } else {
            int current = mp2[key];
            mp1[current].erase(key);
            if (mp1[current].size() == 0)
                mp1.erase(current);
            mp1[(current + 1)].insert(key);
            mp2[key]++;
        }
    }

    void dec(string key) {
        int count = mp2[key];
        mp1[count].erase(key);
        if (mp1[count].size() == 0)
            mp1.erase(count);
        count--;
        if (count == 0) {
            mp2.erase(key);

        } else {
            mp2[key] = count;
            mp1[count].insert(key);
        }
    }

    string getMaxKey() {

        if (mp1.size() == 0)
            return "";

        auto it = mp1.end();
        it--;

        string str = *(it->second).begin();
        return  str;
    }

    string getMinKey() {
        if (mp1.size() == 0)
            return "";

        auto it = mp1.begin();

           string str = *(it->second).begin();
        return  str;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */