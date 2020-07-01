class Solution {
public:
    static bool sort1(const vector<int> &v1,const vector<int> &v2)
    {        
        for(int i=0;i<v1.size()-1;i++)        //goes for every rank
        {
            if(v1[i]!=v2[i]){
              return v1[i]>v2[i];          
            }            
        }     
        return v1.back()<v2.back();         //sorting by team letter 
    }  
    string rankTeams(vector<string>& votes) {
        int n = votes.size();        
        int nt = votes[0].size();
        vector<vector<int>> m(26, vector<int>(nt+1,0));
        
        for(int rank=0;rank<nt;rank++)              //on every rank
        {
            for(int i=0;i<n;i++)                               //on every vote
            {
                int c = votes[i][rank]-'A';                     //Current character 0..25          
                m[c][rank]++;                                      // count no of votes at position rank for team c
                m[c][nt] = votes[i][rank];                     // keep character at the end of the list
            }                        
        }        
        sort(m.begin(),m.end(), sort1);                   // sort vectors based on ranks and Team name if ranks are same
        string res="";        
        for(int i=0;i<m.size();i++)                 
        {
            if(m[i].back()!=0)               //if character was present in ranking system
                res+=m[i][nt];
        }            
        return res;
    }
};