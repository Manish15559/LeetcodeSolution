class MedianFinder {
public:

    priority_queue<int>leftHalf;  //maxHeap
    priority_queue<int,vector<int>,greater<int>>rightHalf; //minHeap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        rightHalf.push(num);
        int val=rightHalf.top();
        rightHalf.pop();
        leftHalf.push(val);
        if((leftHalf.size()-rightHalf.size())>1){
            int valAddToRightHalf = leftHalf.top();
            leftHalf.pop();
            rightHalf.push(valAddToRightHalf);
        }
        
    }
    
    double findMedian() {
        int n=leftHalf.size()+rightHalf.size();
        if(n%2==1) return leftHalf.top();
        else return (1.0*(leftHalf.top()+rightHalf.top()))/2;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */