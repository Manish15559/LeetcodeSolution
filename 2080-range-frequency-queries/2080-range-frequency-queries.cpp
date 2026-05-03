class RangeFreqQuery {
public:
    unordered_map<int,vector<int>>list;
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        // adj.resize(n);
        for(int i=0;i<n;i++){
            list[arr[i]].push_back(i);

        }
        
    }
    
    int query(int left, int right, int value) {
        if(list.find(value)==list.end()) return 0;
        int idx2=upper_bound(list[value].begin(),list[value].end(),right)-list[value].begin();
        idx2--;
        int idx1=lower_bound(list[value].begin(),list[value].end(),left)-list[value].begin();

        return (idx2-idx1+1);
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */