class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int mx=0;
        int totalones=0;
        for(auto i:s){
            if(i=='1')totalones++;
        }
        int lones=s[0]=='1'?1:0;
        for(int i=1;i<n;i++){       try every partition
            int temp=0;
            int l0=i-lones;
            int r1=totalones-lones;
            temp=l0+r1;
            mx=max(mx,temp);
            lones+=s[i]=='1'?1:0;
        }
        return mx;
    }
};