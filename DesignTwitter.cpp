// Design Twitter
#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int timeStamp;
    unordered_map<int, set<int>> following;  // user → set of followees
    unordered_map<int, vector<pair<int,int>>> tweets; // user → [(time, tweetId)]

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; // (time, tweetId)

        // Add user's own tweets
        for (auto &t : tweets[userId])
            pq.push(t);

        // Add followees' tweets
        for (int followee : following[userId]) {
            for (auto &t : tweets[followee])
                pq.push(t);
        }

        vector<int> feed;
        int count = 0;

        // Get top 10 most recent tweets
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // can't follow self
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId))
            following[followerId].erase(followeeId);
    }
};
