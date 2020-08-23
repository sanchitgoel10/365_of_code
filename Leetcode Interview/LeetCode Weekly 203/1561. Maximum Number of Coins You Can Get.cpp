class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.begin(),piles.end());
        int i=0,j=piles.size()-1,k=j-1;
        while(i<k){
            ans+=piles[k];
            i++;
            j-=2;
            k-=2;
        }
        return ans;
    }
};