#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
    long long l = 0, r = num;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long sqmid = mid * mid;
        if (sqmid > num) r = mid - 1;
        else if (sqmid < num) l = mid + 1;
        else return true;
    }
    return false;
}
};