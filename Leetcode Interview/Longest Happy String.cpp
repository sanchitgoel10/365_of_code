class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        if(!a && !b && !c) return "";
        priority_queue<pair<int, string>> pq;
        if(a) pq.push({a, "a"}); 
        if(b) pq.push({b, "b"});
        if(c) pq.push({c, "c"});
        string res = ""; 
        int state = 1;         //count of the llast letter.
        auto pr = pq.top(); pq.pop();
        res +=pr.second; 
        pq.push({pr.first-1, pr.second});
        string last = pq.top().second;
        while(!pq.empty() && state!=3) {
            auto pr = pq.top(); pq.pop(); 
            if(pr.second==last) {
                if(state==2) {
                    if(pq.empty()) return res;
                    auto pr2 = pq.top(); pq.pop(); 
                    res += pr2.second;
                    if(pr2.first>1) pq.push({pr2.first-1, pr2.second});
                    pq.push({pr.first, pr.second}); 
                    state = 1;
                    last = pr2.second;
                } else {
                    res +=pr.second; 
                    if(pr.first>1) pq.push({pr.first-1, pr.second}); 
                    ++state;
                }
            } else {
                res +=pr.second; 
                if(pr.first>1) pq.push({pr.first-1, pr.second}); 
                state = 1; 
                last = pr.second; 
            }
        }
        return res;
    }
};