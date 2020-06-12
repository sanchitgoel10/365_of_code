class Twitter {
public:
    
    unordered_map<int,unordered_set<int>> fo;
    unordered_map<int,vector<pair<int,int>>> t;
    
    long long time;
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++,tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> q;     //max heap according to time
        for(auto x:t[userId]){           //self tweets           
            q.push(x);
        }
        for(auto i:fo[userId]){     //for every follower
            for(auto j:t[i]){        //followers evry tweet
                q.push(j);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            if(ans.size()==10)break;
            auto x=q.top();
            ans.push_back(x.second);
            q.pop();
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            fo[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
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