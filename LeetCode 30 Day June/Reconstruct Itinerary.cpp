
/*
Euler's Path concept of backtracking when getting stuck
https://youtu.be/8MpoO2zA2l4(video link)
*/

class Solution{
public:
    map<string,multiset<string>> graph;      //multiset keeps take care of sorting
    vector<string> res;
    void go(string d){
        while(graph[d].size()){
            auto next = *graph[d].begin();
            graph[d].erase(graph[d].begin());
            go(next);
        } 
        res.push_back(d);
    }
    vector<string> findItinerary(vector<vector<string>> tickets) {
        for(auto& t: tickets) graph[t[0]].insert(t[1]);
        go("JFK");
        return vector<string>(res.rbegin(),res.rend());                //gives reverse order watch video
    }   
};