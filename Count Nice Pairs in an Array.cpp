// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Count Nice Pairs in an Array (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int mod = 1e9+7;
    
    int reverse(int x)
    {
        int result = 0;
        while(x)
        {
            result *= 10;
            result += (x % 10);
            x /= 10;
        }
        return result;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> cache;
        int result = 0;
        
        for(int &x : nums)
        {
            x -= reverse(x);
            result = (result + cache[x]) % mod;;
            cache[x]++;
        }
        return result;
    }
};
