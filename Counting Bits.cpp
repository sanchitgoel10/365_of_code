
/*
i&(i-1) drops the lowest set bit. For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100, the number of "1" in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1
*/


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};



/*Let's denote the number as num:

If it is even, the ending bit is 0, then that bit can be ignored, countBits(num) is the same as countBits(num >> 1), so countBits(num) = countBits(num >> 1);

For example:

num:      101010101010
num >> 1: 10101010101
If it is odd, the ending bit is 1, then the number of set bits is that of num - 1 + 1, i.e. countBits(num) = countBits(num - 1) + 1

For example:

num:     101010101011
num - 1: 101010101010
Final code
*/
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        res[0] = 0;
        
        for(int i = 1; i <= num; i++){
            if((i & 1) == 0){
                res[i] = res[i >> 1];
            }else{
                res[i] = res[i - 1] + 1;
            }
        }
        
        return res;
    }
}