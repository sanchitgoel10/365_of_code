/*
Let's assume we have a fixed size of window (minSize), we can easily use a sliding window of that size and check for the contraints within that window.
This can be done in O(n) using a hashmap to store the unique count of letters in the window.

The greedy part of the solution is that, we also notice that we only need minSize since if the minSize satisfies the constraints to have distinct letters <= maxLetters any substring greater than that size would only add at max a new distinct letter.
We need to find all substrings that meet specific criteria. We can do it in O(n) using a rolling window approach.
Since we process all matching substring, we can just use a hash map to count their occurrences.
*/
int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int i = 0, j = 0, unique = 0, res = 0, cnt[26] = {};
    unordered_map<string, int> m;       //to store minSize substr 
    while (j < s.size()) {
        if (++cnt[s[j++] - 'a'] == 1) ++unique;
        while (unique > maxLetters || j - i > minSize)
            if (--cnt[s[i++] - 'a'] == 0) --unique;
        if (j - i == minSize)                         //only care about minsize strings
            res = max(res, ++m[s.substr(i, minSize)]);
    }
    return res;
}