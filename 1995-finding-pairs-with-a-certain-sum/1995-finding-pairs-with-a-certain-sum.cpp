class FindSumPairs {
public:
 unordered_map<int,int>freq;
 vector<int>arr1;
 vector<int>arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
       
        for(auto it:nums2) freq[it]++;

        arr1=nums1;
        arr2=nums2;
        
    }
    
    void add(int index, int val) {

        freq[arr2[index]]--;
        freq[(arr2[index]+val)]++;
        arr2[index]+=val;
        
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it:arr1){
            ans+=freq[(tot-it)];
        }
        return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */