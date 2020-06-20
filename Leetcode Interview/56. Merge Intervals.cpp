class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        vector<vector<int>> ans;
        if(intervals.size()==0)return ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ans.back()[1]){
                vector<int> x=ans.back();
                ans.pop_back();
                ans.push_back({x[0],max(intervals[i][1],x[1])});
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};