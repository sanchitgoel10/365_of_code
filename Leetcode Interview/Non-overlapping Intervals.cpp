
//same as selecting max activities but reverse
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)return 0;
        auto cmp = [](const vector<int>& p1, const vector<int>& p2){
            return p1[1]<p2[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        
        int activitiestaken=1;
        int prev=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[prev][1]){
                activitiestaken++;
                prev=i;
            }
        }
        return intervals.size()-activitiestaken;
    }
};