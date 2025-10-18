class RandomizedCollection {
public:
unordered_map<int,unordered_set<int>>mp; //{val, idxs where its present}
vector<int>arr;

    RandomizedCollection() {
        
    }
    bool isPresent(int val){
        if(mp.find(val)!=mp.end()) return true;
        return false;
    }
    
    bool insert(int val) {
        arr.push_back(val);
        if(isPresent(val)){
            mp[val].insert((arr.size()-1));
            return false;
        }
        else{
            mp[val].insert((arr.size()-1));
            return true;
        }
        
    }
    
    bool remove(int val) {
        if(isPresent(val)==false) return false;

        
        auto it=mp.find(val);
        int idx=*((it->second).begin());
        if(arr[idx]==arr[arr.size()-1]){
            mp[val].erase((arr.size()-1));
             if(mp[val].size()==0) mp.erase(val);
            
            arr.pop_back();
            return  true;

        }
        
        arr[idx]=arr.back();
        mp[val].erase(idx);
        mp[arr[idx]].erase((arr.size()-1));
        mp[arr[idx]].insert(idx);
        
        arr.pop_back();

        
        
        
        
        if(mp[val].size()==0) mp.erase(val);

        return true;

        
    }
    
    int getRandom() {

        return arr[rand()%(arr.size())];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */