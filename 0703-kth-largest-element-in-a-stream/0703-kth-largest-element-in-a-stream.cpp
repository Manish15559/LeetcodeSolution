class KthLargest {
public:
    int length;
    priority_queue<int,vector<int>,greater<int>>KLargestElements;
    KthLargest(int k, vector<int>& nums) {
        length=k;
        for(auto num:nums) add(num);
        
    }
    
    int add(int val) {
        KLargestElements.push(val);
        while(KLargestElements.size()>length) KLargestElements.pop();
        return KLargestElements.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */