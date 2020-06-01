class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int prev=-1;
        int n=S.length();
        vector<int> ans(n,100000);
        for(int i=0;i<n;i++){
            if(S[i]==C){
                prev=i;
                ans[i]=0;
            }else{
                if(prev!=-1)ans[i]=i-prev;
            }
        }
        prev=-1;
        for(int i=n-1;i>=0;i--){
            if(S[i]==C){
                prev=i;
            }else{
                if(prev!=-1){
                    ans[i]=min(ans[i],prev-i);
                }
            }
        }
        return ans;
    }
};