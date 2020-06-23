class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0,j=h.size()-1;
        int ans=(j-i)*min(h[i],h[j]);
        while(i<j){
            if(h[i]>h[j]){
                j--;
                ans=max(ans,(j-i)*(min(h[i],h[j])));
            }else{
                i++;
                ans=max(ans,(j-i)*(min(h[i],h[j])));
            }
        }
        return ans;
    }
};