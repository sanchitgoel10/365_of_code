class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end());
        int ans=1;
        vector<int> prev=points[0];
        for(int i=1;i<points.size();i++){
            vector<int> curr=points[i];
            int l=prev[0];
            int r=prev[1];
            int s=curr[0];
            int e=curr[1];
            if(e<l||s>r){
                prev=curr;
                ans++;
            }else{
                prev[0]=max(l,s);
                prev[1]=min(r,e);
            }
        }
        return ans;
    }
};