// General Idea:
    // - Brute force checking will time out, we need efficent way to look up words
    // - Create an vector that stores indices for each character a-z in S
    // - Then for each word, do a binary search for next index for current character in word 
    //   that is greater than the index we last found for the alst character
    // - If it doesn't exist, word doesn't exist, otherwise continue to search for word


class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> m(26);
        for(int i=0;i<S.size();i++){
            m[S[i]-'a'].push_back(i);
        }
        
        int ans=0;
        for(auto w:words){
            int x=-1;
            bool found=true;
            for(auto c:w){
                int i=c-'a';
                auto it=upper_bound(m[i].begin(),m[i].end(),x);    //next greater index 
                if(it==m[i].end()){
                    found=0;
                    break;
                }
                x=*it;    //update last index
            }
            if(found)ans++;
        }
        return ans;
    }
};