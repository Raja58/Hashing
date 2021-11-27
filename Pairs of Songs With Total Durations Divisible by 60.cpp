// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Pairs of Songs With Total Durations Divisible by 60 (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> cache;
        int result = 0;
        for(int x : time)
        {
            x %= 60;
            if(cache.find((60 - x) % 60) != cache.end())
                result += cache[(60 - x) % 60];
            cache[x]++;
        }
        return result;
    }
};
