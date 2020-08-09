/*
This is similar to 1371. Find the Longest Substring Containing Vowels in Even Counts.

We can form a palindrome if the count of each included number (expcept maybe one) is even, and this is the property of an awesome string.

A bit in our mask is 0 if the count for the corresponding number is even, and 1 if it's odd. As we go through the string, we track odd/even counts in our mask. If we see the same mask again, the subarray between first poistion (exclusive) and the current position (inclusive) with the same mask has all numbers with the even count.

We will use the dp array to track the smallest (first) position of each mask. We can get the size of the substring by substracting it from the current poisition.

Note that position for zero mask is -1, as we need to include the very first character.

Now, the difference from #1371 is that a palindrome can have up to one number with the odd count. Therefore, we need to also check all masks that are different from the current one by one bit. In other words, if two masks are different by one bit, that means that there is one odd count in the substring.

*/
class Solution {
public:
     int longestAwesome(string s) {
        int res = 0, cur = 0, n = s.size();
        vector<int> seen(1024, n);
        seen[0] = -1;
        for (int i = 0; i < n; ++i) {
            cur ^= 1 << (s[i] - '0');
            res = max(res, i - seen[cur]);
            for (int a = 0; a < 10; ++a)                     //forthe all possible odd cases
                res = max(res, i - seen[cur ^ (1 << a)]);
            seen[cur] = min(seen[cur], i);
        }
        return res;
    }
};