class Solution {
public:
    
    static bool compare(const pair<string,int>&a,const pair<string,int>&b){
        if(a.first.size()==b.first.size()){
            return a.second<b.second;
        }
        return a.first.size()<b.first.size();
    }
    
    string arrangeWords(string text) {
        vector<pair<string,int>>v;
        string prev="";
        int ind=0;
        text[0]+=32;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                v.push_back({prev,ind});
                ind++;
                prev="";
            }else{
                prev+=text[i];
            }
        }
        v.push_back({prev,ind});
        sort(v.begin(),v.end(),compare);
        string ans="";
        for(int i=0;i<v.size();i++){
            ans+=v[i].first;
            if(i!=v.size()-1)ans+=" ";
        }
        ans[0]=ans[0]-32;
        return ans;
    }
};