class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);   //sorting req as all the small length word should be entered in map already
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words) {
            for (int i = 0; i < w.length(); i++)
                dp[w] = max(dp[w], dp[w.substr(0, i) + w.substr(i + 1)] + 1);
            res = max(res, dp[w]);
        }
        return res;
    }
};