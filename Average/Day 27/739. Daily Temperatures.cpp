class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        stack<pair<int,int>> s;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int curr=T[i];
            while(!s.empty()&&curr>=s.top().first)s.pop();
            ans[i]=s.empty()?0:s.top().second-i;
            s.push({T[i],i});
        }
        return ans;
    }
};