class MyCalendar {
public:
vector<pair<int,int>>arr;
    MyCalendar() {
        
        
    }
    bool isOverlapping(pair<int,int>a,pair<int,int>b){
        return max(a.first,b.first)<min(a.second,b.second);
    }
    
    bool book(int startTime, int endTime) {
        for(auto it:arr){
            if(isOverlapping({startTime,endTime},it)) return false;
        }
        arr.push_back({startTime,endTime});
        return true;

        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */