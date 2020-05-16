class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        unordered_map<int,vector<int> > m;
        for(int i=1;i<n;i++){
            for(int j=2;j<=n;j++){
                if(i>=j)continue;
                int g =__gcd(i,j);
                int x=i/g;
                int y=j/g;
                if(find(m[x].begin(),m[x].end(),y)==m[x].end()){
                    string temp=to_string(i)+"/"+to_string(j);
                    ans.push_back(temp);
                    m[i].push_back(j);
                }
            }
        }
        return ans;
    }
};