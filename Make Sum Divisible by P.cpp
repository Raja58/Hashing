// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        28 Nov 2021
//  @Detail  :        Make Sum Divisible by P (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = accumulate(nums.begin(), nums.end(), 0ll) % p;
        if(rem == 0)
            return 0;
      
        unordered_map<int, int> cache;
        cache[0] = -1;
        int result = INT_MAX, cur = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur = (cur + nums[i]) % p;
            cache[cur] = i;
            if(cache.find((cur - rem + p) % p) != cache.end())
                if(result > i - cache[(cur - rem + p) % p])
                    result = i - cache[(cur - rem + p) % p];
        }
        return result < nums.size() ? result : -1;
    }
};
