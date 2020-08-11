class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())return 0;
        int n=citations.size();
        vector<int> freq(n+1,0);
        
        for(int i=0;i<n;i++){
            if(citations[i]>=n)freq[n]++;
            else freq[citations[i]]++;
        }
        
        int paper=0;
        for(int i=n;i>=0;i--){
            paper+=freq[i];
            if(paper>=i){
                return i;
            }
        }
        return 0;
    }
};