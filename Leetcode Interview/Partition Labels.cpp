class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26]={0};
        for(int i=0;i<S.size();i++){
            last[S[i]-'a']=i;
        }
        vector<int> v;
        int end=0;
        int start=0;
        for(int i=0;i<S.size();i++){
            end=max(end,last[S[i]-'a']);
            if(i==end){
                v.push_back(end-start+1);
                start=i+1;
            }
        }
        return v;
    }
};