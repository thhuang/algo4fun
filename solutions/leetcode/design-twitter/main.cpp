class Twitter {
    unordered_map<int, vector<int>> userTweetTimes;
    unordered_map<int, unordered_set<int>> followInfo;
    vector<int> tweets;

    struct TweetInfo {
        vector<int>::reverse_iterator it, end;
    };

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        userTweetTimes[userId].push_back(tweets.size());
        tweets.push_back(tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        auto cmp = [&](TweetInfo a, TweetInfo b) -> bool {
            return *a.it < *b.it;
        };
        priority_queue<TweetInfo, vector<TweetInfo>, decltype(cmp)> pq(cmp);
        followInfo[userId].insert(userId);
        for (int u : followInfo[userId]) {
            auto it = userTweetTimes[u].rbegin();
            auto end = userTweetTimes[u].rend();
            if (it == end) continue;
            pq.push({it, end});
        }

        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            auto [it, end] = pq.top();
            pq.pop();

            result.push_back(tweets[*it]);

            if (++it == end) continue;

            pq.push({it, end});
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followInfo[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followInfo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
