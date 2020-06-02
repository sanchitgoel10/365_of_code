/*If we want to replace the characters in a substring(that particular range) and make it into the longest repeating, then we definitely want to find the character with maximum frequency and then replace all the other characters by this one, hence in this way, we can minimize the number of replacement.
(the length of the window) - (the maximum frequency of the character in this window) > k
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ctr[91] = {};
        int ans=0;
        while (j < s.size()) {
            ctr[s[j++]]++;
            if (j-i - *max_element(ctr+65, ctr+91) > k)          //65-91 range hai capital letters ki 
                ctr[s[i++]]--;
            ans=max(ans,j-i);
        }
        return ans;
    }
    
};