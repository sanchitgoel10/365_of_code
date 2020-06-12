//Normal Kmp preprocessing work
class Solution {
public:
    string longestPrefix(string s) {
        vector<int> kmp(s.size(),0);
        int i=1,j=0;
        while(i<s.size()){
            if(s[i]==s[j]){
                kmp[i]=j+1;
                i++;
                j++;
            }else{
                if(j==0){
                    kmp[i]=0;
                    i++;
                }else{
                    j=kmp[j-1];
                }
            }
        }
        return s.substr(0,kmp[s.size()-1]);
    }
};
//New smart but with some limitations solutionn
//Hashing solution
/*
Compute hashes for increasing prefix and suffix, reusing the previously computed hashes. This is similar to the Karp–Rabin algorithm.

For the string of i size, the hash is: s[0] * 26 ^ (i - 1) + s[1] * 26 ^ (i -2) + ... + s[i - 2] * 26 + s[i - 1].

For the prefix hash, we will multiply the previous value by 26 and add a new letter.
For the suffix hash, we add a new letter multiplied by 26 ^ (i - 1).
Note that we need to use some large prime as a modulo to avoid overflow errors, e.g. 10 ^ 9 + 7.

Beware of collisions. After you find a matching hash, you need to check the string. Since OJ test cases do not cause collisions, I am not doing it here.

*/
string longestPrefix(string &s) {
    long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
        int first = s[i] - 'a', last = s[j] - 'a';
        h1 = (h1 * 26 + first) % mod;
        h2 = (h2 + mul * last) % mod;
        mul = mul * 26 % mod;
        if (h1 == h2)
            len = i + 1;
    }
    return s.substr(0, len);
}