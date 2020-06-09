/*
Condition 1. odd characters <= k
Count the occurrences of all characters.
If one character has odd times occurrences,
there must be at least one palindrome,
with odd length and this character in the middle.
So we count the characters that appear odd times,
the number of odd character should not be bigger than k.

Condition 2. k <= s.length()
Also, if we have one character in each palindrome,
we will have at most s.length() palindromes,
so we need k <= s.length().

The above two condition are necessary and sufficient conditions for this problem.
So we return odd <= k <= n


Construction
@spjparmar immediately got a question like why this works always for all strings.
He gave the some following dry runs. :)
For any string with 0 odd character count , we can form k no. of palindrome strings for sure with k<=n
(This is why k<=n)
eg -
aabb , k=1| abba
aabb, k=2 | aa, bb
aabb, k=3 | a, a, bb,
aabb, k=4 | a,a,b,b

For any string with odd character count <=k , we can always form k palindrome string for sure with k<=n
eg2 -
aabbc, k=1 | aacbb
aabbc, k=2 | aca, bb
aabbc, k=3 | a,a, bcb
aabbc, k=4 | a, a, c ,bb
aabbc, k=5 | a, a, c, b, b

eg3 -
aabc, K=1 | aabc
aabc, K=2 | aba, c
aabc, K=3 | aa, b, c
aabc, K=4 | a, a, b, c

Hope this helps somebody.
*/
 bool canConstruct(string s, int k) {
        bitset<26> odd;
        for (char& c : s)
            odd.flip(c - 'a');
        return odd.count() <= k && k <= s.length();
    }