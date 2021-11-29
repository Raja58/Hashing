// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Number of Pairs of Interchangeable Rectangles (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<int> getRatio(vector<int> x)
    {
        int gcd = __gcd(x[0], x[1]);
        return vector<int> {x[0] / gcd, x[1] / gcd};
    }
    
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<vector<int>, long long> cache;
        long long result = 0;
        
        for(vector<int> &x : rectangles)
        {
            x = getRatio(x);
            result += cache[x];
            cache[x]++;
        }
        return result;
    }
};
