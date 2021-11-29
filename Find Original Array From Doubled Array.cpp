// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Find Original Array From Doubled Array (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n & 1)
            return {};
        
        sort(changed.begin(), changed.end());
        unordered_map<int, int> cache;
        
        for(int &x : changed)
            cache[x]++;
        
        vector<int> original;
        
        for(int i = 0; i < n; i++)
        {
            if(cache[changed[i]] == 0)
                continue;
            
            cache[changed[i]]--;
            if(cache[2 * changed[i]] == 0)
                return vector<int> {};
            cache[2 * changed[i]]--;
            original.push_back(changed[i]);
        }
        return original;
    }
};
