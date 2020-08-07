/*
In ASCII codes, character ‘A’ is integer 65 = (0100 0001)2, while character ‘a’ is integer 97 = (0110 0001)2. Similarly, character ‘D’ is integer 68 = (0100 0100)2, while character ‘d’ is integer 100 = (0110 0100)2.
*/
class Solution {
    void backtrack(string &s, int i, vector<string> &res) {    //s ko by reference karna hai pass ya nhi marzi hai
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};