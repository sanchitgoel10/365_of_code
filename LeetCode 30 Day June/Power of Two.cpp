class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcountll(n)==1;
    }
};