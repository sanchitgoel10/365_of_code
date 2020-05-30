class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int>&b){
        return sqrt((a[0])*a[0]+a[1]*a[1])<sqrt((b[0])*b[0]+b[1]*b[1]);     //sqrt ki jarurat nhi waise lol
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),cmp);
        vector<vector<int>> ans;
        for(int i=0;i<K;i++){
            ans.push_back(points[i]);
        }
        return ans;
    }
};