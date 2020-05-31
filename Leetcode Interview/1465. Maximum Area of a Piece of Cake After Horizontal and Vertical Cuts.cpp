class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        sort(hcuts.begin(),hcuts.end());
        sort(vcuts.begin(),vcuts.end());
        int maxh=max(hcuts[0],h-hcuts.back());     //max horizontal slab
        int maxv=max(vcuts[0],w-vcuts.back());     //max vertical slab
        for(int i=0;i<hcuts.size()-1;i++){
            maxh=max(maxh,hcuts[i+1]-hcuts[i]);
        }
        for(int i=0;i<vcuts.size()-1;i++){
            maxv=max(maxv,vcuts[i+1]-vcuts[i]);
        }
        return (long)maxh*maxv%1000000007;
    }
};