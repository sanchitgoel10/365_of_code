class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());          //isme root folder sort karke hamesha upar ayega
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string root = ans.back()+'/';                //agar koi subfolder hoga to vo is formaat ka hoga
            if(folder[i].substr(0,root.size())!=root){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};