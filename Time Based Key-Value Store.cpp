// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Time Based Key-Value Store (LeetCode)
//  ============================
//  -->

class TimeMap {
public:
    
    map<string, map<int, string>> cache;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        cache[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(cache.find(key) == cache.end())
            return "";
        
        auto it = cache[key].lower_bound(timestamp);
        if((*it).first == timestamp)
            return (*it).second;
        
        if(it == cache[key].begin())
            return "";
        it--;
        return (*it).second;
    }
};
