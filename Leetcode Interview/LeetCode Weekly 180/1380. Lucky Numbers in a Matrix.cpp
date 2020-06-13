class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> s;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int mn=INT_MAX;
            for(int j=0;j<m;j++){
                mn=min(mn,matrix[i][j]);
            }
            s.insert(mn);
        }
        vector<int> ans;
        for(int j=0;j<m;j++){
            int mx=0;
            for(int i=0;i<n;i++){
                mx=max(mx,matrix[i][j]);
            }
            if(s.find(mx)!=s.end())ans.push_back(mx);
        }
        return ans;
    }
};