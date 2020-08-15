class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)return 0;
        vector<pair<int,int>> p;
        for(auto v:intervals){
            p.push_back({v[1],v[0]});
        }
        sort(p.begin(),p.end());
        int ans=1;
        int l=p[0].first;
        for(int i=1;i<p.size();i++){
            if(p[i].second>=l){
                ans++;
                l=p[i].first;
            }
        }
        return p.size()-ans;
    }
};