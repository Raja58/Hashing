// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Seat Reservation Manager (LeetCode)
//  ============================
//  -->

class SeatManager {
public:
    
    int n;
    set<int> seat;
    
    SeatManager(int m) {
        n = m;
        for(int i = 1; i <= n; i++)
            seat.insert(i);
    }
    
    int reserve() {
        int result = *seat.begin();
        seat.erase(seat.begin());
        return result;
    }
    
    void unreserve(int seatNumber) {
        seat.insert(seatNumber);
    }
};
