// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Array of Doubled Pairs (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isPossible(vector<int> &arr, bool isPos)
    {
        if(isPos)
            sort(arr.begin(), arr.end());
        else
            sort(arr.begin(), arr.end(), greater<int>());
        
        unordered_map<int, int> cache;
        for(int &x : arr)
            cache[x]++;
        
        for(int &x : arr)
        {
            if(cache[x] == 0)
                continue;
            cache[x]--;
            if(cache[2 * x] == 0)
                return false;
            cache[2 * x]--;
        }
        return true;
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        if(n & 1)
            return false;
        
        vector<int> pos, neg;
        for(int &x : arr)
            if(x >= 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        
        if(pos.size() & 1)
            return false;
        
         return isPossible(pos, true) && isPossible(neg, false);
    }
};
