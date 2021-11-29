// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Design Twitter (LeetCode)
//  ============================
//  -->

class Twitter {
public:
    
    struct detail{
        int time;
        int tweetId;
        bool operator<(const detail &x) const{
            return time > x.time;
        }
    };
    
    int curTime;
    unordered_map<int, unordered_set<int>> followed;
    unordered_map<int, vector<detail>> posts;
    
    Twitter() {
        curTime = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({curTime++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<detail> newsFeed;
        
        for(detail &x : posts[userId])
        {
            newsFeed.push(x);
            if(newsFeed.size() > 10)
                newsFeed.pop();
        }
        
        for(auto &x : followed[userId])
        {
            for(detail &y : posts[x])
            {
                newsFeed.push(y);
                if(newsFeed.size() > 10)
                    newsFeed.pop();
            }
        }
        
        while(!newsFeed.empty())
        {
            result.push_back(newsFeed.top().tweetId);
            newsFeed.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);
    }
};
