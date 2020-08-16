/*
As pleasant as it seems, it does not make sense to just keep eating oranges one by one.

So, the real choice we have is to eat n % 2 oranges one-by-one and then swallow n / 2, or eat n % 3 oranges so that we can gobble 2 * n / 3.

As usual, we use DP to avoid re-computation. Since our numbers can be large, it's better to use a hash map instead of an array.
----n%2 or n%3 is how much distance away n is from being divisible by 2 or 3 (which is done by just subtracting 1), which is best way to minimize the steps
----1 is added because of operations(2nd or 3rd as specified in question) done to decrease n -> n/2 or n -> n/3
C++
*/

class Solution {
public:
    unordered_map<int, int> dp;
    int minDays(int n) {
        if (n <= 1)
            return n;
        if (dp.count(n) == 0)
            dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }
};