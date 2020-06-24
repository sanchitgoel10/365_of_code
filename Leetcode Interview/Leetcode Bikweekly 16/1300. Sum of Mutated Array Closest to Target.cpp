/*Binary search solution
See also a sorting solution below.

The value we are looking for is somewhere between 1 and maxValue (m).
Now use Binary search to speed up the process.

go up if the sum is too small
go down if the sum is too big
When we are done with binary search, l and r are equal, but it might happen that we have not exactly reached the target.
Check if l-1 (should get us below the target) leads to the sum closer to the target.
*/class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l, r, mi, s=0, m=-1;
        for(int v:arr) s += v, m=max(m,v);

        if(s<=target) return m; // return the max value since we will keep all nums as it is

        for(l=1,r=m;l<r;) {
            mi=(l+r)/2;
            s=0;
            for(int v:arr) s += (v>mi)?mi:v;
            if(s>=target) r=mi;
            else l=mi+1;
        }
        // check if we are 1 step off the target 
        int s1=0,s2=0;
        for(int v:arr) s1 += (v>l)?(l):v, s2 += (v>l-1)?(l-1):v;
        
        return (abs(s2-target) <= abs(s1-target)) ? l-1 : l;
    }
};