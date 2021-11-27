// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Fruit Into Baskets (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), start = 0, result = 0;
        unordered_map<int, int> cache;
        
        for(int end = 0; end < n; end++)
        {
            cache[fruits[end]]++;
            while(cache.size() > 2 && start <= end)
            {
                if(result < end - start)
                    result = end - start;
                cache[fruits[start]]--;
                if(cache[fruits[start]] == 0)
                    cache.erase(fruits[start]);
                start++;
            }
        }
        if(result < n - start)
            result = n - start;
        return result;
    }
};
