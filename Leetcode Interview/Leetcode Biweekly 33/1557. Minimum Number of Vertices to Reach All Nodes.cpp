class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> seen(n,0);
        vector<int> ans;
        for(auto e:edges){
            seen[e[1]]=1;
        }
        for(int i=0;i<n;i++){            //nodes with no in degree
            if(!seen[i])ans.push_back(i);
        }
        return ans;
    }
};