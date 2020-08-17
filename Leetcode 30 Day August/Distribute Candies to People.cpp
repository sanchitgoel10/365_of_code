class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n,0);
        int i=0;
        int x=1;
        while(candies){
            ans[i]+=min(candies,x);
            candies=max(candies-x,0);
            x++;
            i=(i+1)%n;
        }
        return ans;
    }
};