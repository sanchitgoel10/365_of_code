class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string, double>> m;
        vector<double> res;
        for (int i = 0; i < values.size(); ++i)
        {
            m[equations[i][0]].insert(make_pair(equations[i][1],values[i]));
            if(values[i]!=0)
                m[equations[i][1]].insert(make_pair(equations[i][0],1/values[i]));
        }

        for (auto i : queries)
        {
            unordered_set<string> s;                //visited
            double tmp = check(i[0],i[1],m,s);
            if(tmp) res.push_back(tmp);
            else res.push_back(-1);
        }
        return res;
    }
    double check(string up, string down, 
            unordered_map<string,unordered_map<string, double>> &m,
            unordered_set<string> &s)
    {
        if(m[up].find(down) != m[up].end()) return m[up][down];
        for (auto i : m[up])
        {
            if(s.find(i.first) == s.end())
            {
                s.insert(i.first);
                double tmp = check(i.first,down,m,s);
                if(tmp){
                    m[i.first].insert(make_pair(down,tmp));          //storing for further reference
                    m[down].insert(make_pair(i.first,1/tmp));
                    return i.second*tmp;
                }
            }
        }
        
        return 0;
    }
};