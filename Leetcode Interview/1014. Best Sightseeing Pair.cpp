class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxp=A[0]+0;    //best value of A[i]+i encountered so far
        int ans=0;
        for(int j=1;j<A.size();j++){
            int x=maxp+A[j]-j;
            ans=max(ans,x);
            maxp=max(maxp,A[j]+j);
        }
        return ans;
    }
};