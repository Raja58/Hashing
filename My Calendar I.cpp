// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        My Calendar I (LeetCode)
//  ============================
//  -->

class MyCalendar {
public:
    
    map<int, int> calendar; //storing like {end, start};
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = calendar.lower_bound(start);
        if(it == calendar.end() || it -> second >= end)
        {
            calendar[end - 1] = start;
            return true;
        }
        return false;
    }
};
