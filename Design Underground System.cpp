// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Design Underground System (LeetCode)
//  ============================
//  -->

class UndergroundSystem {
public:
    
    unordered_map<int, pair<string, int>> inTime;
    unordered_map<string, pair<double, int>> average;
    
    UndergroundSystem() {
        
    }
    
    string getKey(string &a, string &b)
    {
        return a + '-' + b;
    }
    
    void checkIn(int id, string stationName, int t) {
        inTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        double duration = (double)t - inTime[id].second;
        string prevStation = inTime[id].first;
        string key = getKey(prevStation, stationName);
        if(average.find(key) == average.end())
            average[key] = {duration, 1};
        else
        {
            double prevAverage = average[key].first;
            int n = average[key].second;
            double newAverage = (prevAverage * n + duration) / (double)(n + 1);
            average[key] = {newAverage, n + 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = getKey(startStation, endStation);
        return average[key].first;
    }
};
