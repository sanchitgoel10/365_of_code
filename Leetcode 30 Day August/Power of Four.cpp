class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;  //The(num - 1) % 3 == 0is used to distinguish the 4^n from 2^n.
    }
};