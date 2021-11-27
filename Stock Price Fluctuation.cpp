// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Stock Price Fluctuation (LeetCode)
//  ============================
//  -->

class StockPrice {
public:
    
    map<int, int> cache;
    multiset<int> count;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
       if(cache.find(timestamp) != cache.end())
           count.erase(count.find(cache[timestamp]));
        
        cache[timestamp] = price;
        count.insert(price);
    }
    
    int current() {
        return cache.rbegin() -> second;
    }
    
    int maximum() {
        return *count.rbegin();
    }
    
    int minimum() {
        return *count.begin();
    }
};
