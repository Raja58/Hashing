// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Max Number of K-Sum Pairs (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cache;
        int result = 0;
        for(int &x : nums)
        {
            if(cache[k - x])
            {
                result++;
                cache[k - x]--;
            }
            else
                cache[x]++;
        }
        return result;
    }
};
