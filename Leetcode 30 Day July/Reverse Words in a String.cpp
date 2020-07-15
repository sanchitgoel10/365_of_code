class Solution {
public:
    string reverseWords(string s) {
        int i, len, start, end;
        // remove leading spaces
        for (i = 0; i < s.size() && ' ' == s[i]; i++)
            ;
        start = i;
        // remove trailing spaces
        for (i = s.size() - 1; i >= 0 && ' ' == s[i]; i--)
            ;
        end = i;
        // remove multiple spaces btw. words
        for (i = start, len = 0; i <= end; i++) {
            if (' ' == s[i] && ' ' == s[i - 1])
                continue;
            s[len++] = s[i];
        }
        //s.erase(s.begin() + len, s.end()); //removing spaces that we shifted at last
        s.resize(len);     //use this or the above

        reverse(s.begin(), s.end()); //reverse whole string           
        
        for (i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);    //reversing each word to make it normal now
                start = i + 1;
            }
        }
        // last word
        reverse(s.begin() + start, s.end());
        return s;
    }
};