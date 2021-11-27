// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Subarray Sums Divisible by K (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> cache;
        cache[0] = 1;
        
        int sum = 0, result = 0;
        for(int &x : nums)
        {
            sum += ((x % k) + k) % k; // Add k because of negative integers
            if(cache.find(sum % k) != cache.end())
                result += cache[sum % k];
            cache[sum % k]++;
        }
        return result;
    }
};
