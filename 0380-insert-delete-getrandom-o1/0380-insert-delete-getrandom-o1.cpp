class RandomizedSet {
public:
    unordered_map<int,int>mp;  //value, idx at they store in
    vector<int>arr;
    RandomizedSet() {
        

        
    }
    bool search(int val){
        if(mp.find(val)==mp.end()) return false;
        return true;
    }
    
    bool insert(int val) {
        if(search(val)) return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(search(val)==false) return false;
        auto it=mp.find(val);
        int idx=it->second;
        arr[idx]=arr.back();
        arr.pop_back();
        mp[arr[idx]] =idx;
        mp.erase(val);
        return true;


        
    }
    
    int getRandom() {
        return (arr[rand()%arr.size()]);
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */