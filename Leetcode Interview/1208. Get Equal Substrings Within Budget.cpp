/*
At first, I'm confused about why we can just return r - l instead of using Math.max(max, r - l + 1). But now I understand.
The reason is the width of sliding window (in this case) will never be smaller than before: every time you move the left bound of the window, then you move the right bound, in other words, ++l => ++r.

Let's take String s = "abcdaa"; String t = "bcdzzz"; int maxCost = 3; as example:
l: 0, r: 0, charAt(r): (a, b)
l: 0, r: 1, charAt(r): (b, c)
l: 0, r: 2, charAt(r): (c, d)
--- l ++ ---
l: 1, r: 3, charAt(r): (d, z)
--- l ++ ---
l: 2, r: 4, charAt(r): (a, z)
--- l ++ ---
l: 3, r: 5, charAt(r): (a, z)
*/


//Time O(n) space O(n)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=abs(s[i]-t[i]);      //Calculate the differences between a[i] and b[i].
        }
        int i=0,j=0;
        while(j<n){
            maxCost-=diff[j++];
            if(maxCost<0)maxCost+=diff[i++];
        }
        return j-i;
    }
};

//Space O(1)
int equalSubstring(string s, string t, int k) {
        int n = s.length(), i = 0, j;
        for (j = 0; j < n; ++j) {
            if ((k -= abs(s[j] - t[j])) < 0)
                k += abs(s[i] - t[i++]);
        }
        return j - i;
    }