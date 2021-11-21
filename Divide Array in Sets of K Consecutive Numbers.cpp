// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        21 Nov 2021
//  @Detail  :        Divide Array in Sets of K Consecutive Numbers (LeetCode)
//  ============================
//  -->

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k)
            return false;
        map<int, int> cache;
        for(int &x : nums)
            cache[x]++;
        
        for(auto it = cache.begin(); it != cache.end(); it++)
        {
            if(it -> second == 0)
                continue;
            int freq = it -> second;
            for(int i = 0; i < k; i++)
                if(cache[it -> first + i] < freq)
                    return false;
                else
                    cache[it -> first + i] -= freq;
        }
        return true;
    }
};
