class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        if(left.size())ans=left.back();
        if(right.size())ans=max(ans,n-right[0]);
        return ans;
    }
};