class RandomizedCollection {
public:
unordered_map<int,vector<int>>mp; //{val, idxes of theat val};
vector<pair<int,int>>arr;

    RandomizedCollection() {
        
    }
    bool search(int val){
        if(mp.find(val)!=mp.end()) return true;
        return false;
    }
    
    bool insert(int val) {
       bool isPresent =!search(val);
       mp[val].push_back((arr.size()));
       arr.push_back({val,mp[val].size()-1});
       cout<<arr.back().first<<" "<<arr.back().second<<endl;
       
       return isPresent;
        
    }
    
    bool remove(int val) {
       if(search(val)==false) return false;
       int idx=mp[val].back();
       auto it=arr.back();
       mp[it.first][it.second]=idx;
       arr[idx]={it.first,it.second};
       arr.pop_back();
       mp[val].pop_back();
       if(mp[val].size()==0) mp.erase(val);

       return true;
        
    }
    
    int getRandom() {

        return arr[rand()%(arr.size())].first;
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */