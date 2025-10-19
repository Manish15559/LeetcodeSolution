class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkIns;   //id -> {startStation, checkIn time}
    unordered_map<string,pair<long long,int>>routes; // startStation endStation -> {totTime,count}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkIns[id];
        checkIns.erase(id);

        string route= startStation + " " + stationName;
        long long duration = t - startTime;

        auto &[totTime, count] = routes[route];
        totTime+=duration;
        count+=1;
        
        
    }
    
    double getAverageTime(string startStation, string endStation) {

        string route= startStation + " " + endStation;

        auto [totTime, count] = routes[route];

        return ((double)totTime)/count;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */