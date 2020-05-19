

//20 ms solution
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {0};
        for (auto t : trips) stops[t[1]] += t[0], stops[t[2]] -= t[0];    //rachit jain trick
        for (auto i = 0; capacity >= 0 && i < 1001; ++i) capacity -= stops[i];
        return capacity >= 0;
    }
};
//16 ms solution  fast isliye hai kyuki saare time stamps pe nhi jaara although unoredered map use nhi kar rahe isliye nhi kar rahe kyuki order map ka matter karta hai
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto &t : trips)
            m[t[1]] += t[0], m[t[2]] -= t[0];
        for (auto &v : m)
            if ((capacity -= v.second) < 0)
                return false;
        return true;
    }
};