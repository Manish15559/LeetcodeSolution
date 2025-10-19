class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIns; // id -> (station, time)
    unordered_map<string, pair<long long, int>> routes; // "A B" -> (totalTime, count)

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkIns[id];
        checkIns.erase(id);

        string route = startStation + " " + stationName;
        int duration = t - startTime;

        auto& [total, cnt] = routes[route];
        total += duration;
        cnt += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + " " + endStation;
        auto [total, cnt] = routes[route];
        return (double)total / cnt;
    }
};
