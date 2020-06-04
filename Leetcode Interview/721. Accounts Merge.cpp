/*
The key task here is to connect those emails, and this is a perfect use case for union find.
to group these emails, each group need to have a representative, or parent.
At the beginning, set each email as its own representative.
Emails in each account naturally belong to a same group, and should be joined by 
assigning to the same parent (let's use the parent of first email in that list);

OPTIMIZATIONs
1)update parent in find. which has been explained.
2)use unordered_map instead of map, since map has to keep elements ordered, it takes more time in insertion.
3)use call by reference.


*/


class Solution {
    private:
    string find(string s, unordered_map<string, string>& p) {   //this is basically get parent
        return p[s]=p[s] == s ? s : find(p[s], p);      //we also do path compression    point 1 above
    }
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string, string> owner;                    //point 2 above
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;      //set inside takes care of the sorting
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {   //loop starting from 1st as at index 0 acc name is present 
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];           //owners is accounts name
            }
        }
        for (int i = 0; i < acts.size(); i++) {                 //merging of parents 
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);     //merging in unions

        vector<vector<string>> res;
        for (const pair<string, set<string>> &p : unions) {              //call by reference point 3
            vector<string> emails(p.second.begin(), p.second.end());          
            emails.insert(emails.begin(), owner[p.first]);     //inseting account name at first position
            res.push_back(emails);
        }
        return res;
    }

};