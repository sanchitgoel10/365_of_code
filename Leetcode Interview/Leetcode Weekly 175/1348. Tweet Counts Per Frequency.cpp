class TweetCounts {
public:
    unordered_map<string, vector<int>>m;
    unordered_map<string, int>f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector <int>res;
        for (int i=0; i <= (endTime - startTime) / f[freq]; i++)       //creating slots
            res.push_back(0);

        for (auto& time : m[tweetName]) {
            if (time >= startTime && time <= endTime) {
                int index = (time - startTime) / f[freq];
                res[index]++;
            }
        }
        return res;
    }
};