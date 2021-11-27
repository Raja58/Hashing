// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Smallest Integer Divisible by K (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long num = 0;
        for(int len = 1; len <= k; len++)
        {
            num = (num * 10 + 1) % k;
            if(num % k == 0)
                return len;
        }
        return -1;
    }
};
