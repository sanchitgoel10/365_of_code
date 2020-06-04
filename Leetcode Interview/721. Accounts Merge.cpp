class Solution {
    private:
    string find(string s, unordered_map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string, string> owner;
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;      //set inside takes care of the sorting
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {   //loop starting from 1st as at index 0 acc name is present 
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];           //owners is accounts name
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);     //merging in unions

        vector<vector<string>> res;
        for (const pair<string, set<string>> &p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());          
            emails.insert(emails.begin(), owner[p.first]);     //inseting account name at first position
            res.push_back(emails);
        }
        return res;
    }

};