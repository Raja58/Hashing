// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Count Good Meals (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int mod = 1e9+7;
    
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> cache;
        int result = 0;
        for(int &x : deliciousness)
        {
            for(int i = 1; i <= (1 << 21); i <<= 1)
            {
                if(cache.find(i - x) != cache.end())
                    result = (result + cache[i - x]) % mod;
            }
            cache[x]++;
        }
        return result;
    }
};
