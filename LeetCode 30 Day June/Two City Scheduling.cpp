/*
Example: [30, 100], [40, 90], [50, 50], [70, 50].
Savings: 70, 50, 0, -20.
*/
class Solution {
public:
    
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]-v1[0]>v2[1]-v2[0];                 //sorting on the basis of the savings if we travel to A rather than B
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int ans=0;
        int n=costs.size();
        for(int i=0;i<n/2;i++){
            ans+=costs[i][0];
        }
        for(int i=n/2;i<n;i++){
            ans+=costs[i][1];
        }
        return ans;
    }
};