//unordered_Set use nhi kar sakte kyuki pair ka hash function nhi hai inbuilt khud banana padega see below

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0,y=0;
        set<pair<int,int>>s;
        s.insert({0,0});
        for(char p: path){
            if(p == 'N') y++;
            else if(p == 'S')y--;
            else if(p == 'E') x++;
            else x--;
            
            if(s.find({x,y}) != s.end()) return true;
            else s.insert({x,y});
        }
        return false;
    }
};
struct ii {
    int first;
    int second;
  };
bool isPathCrossing(string path) {
    auto hash = [](const ii& p) { return p.first + 10001 * p.second; };
    auto equal = [](const ii& p1, const ii& p2) {
      return p1.first == p2.first && p1.second == p2.second;
    };

    unordered_set<ii, decltype(hash), decltype(equal)> points(10001, hash, equal);

    ii curr = {0, 0};
    points.insert(curr);
    for (auto& c : path) {
      switch (c) {
        case 'N': {
          curr.first++;
        } break;
        case 'S': {
          curr.first--;
        } break;
        case 'E': {
          curr.second++;
        } break;
        case 'W': {
          curr.second--;
        } break;
      }
      if (points.count(curr)) {
        return true;
      }
      points.insert(curr);
    }
    return false;
  }