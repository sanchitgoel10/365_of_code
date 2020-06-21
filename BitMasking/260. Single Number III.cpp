/*Let a and b be the two unique numbers
XORing all numbers gets you (a xor b)
(a xor b) must be non-zero otherwise they are equal
If bit_i in (a xor b) is 1, bit_i at a and b are different.
Find bit_i using the low bit formula m & -m   (See below)
Partition the numbers into two groups: one group with bit_i == 1 and the other group with bit_i == 0.
a is in one group and b is in the other.
a is the only single number in its group.
b is also the only single number in its group.
XORing all numbers in a's group to get a
XORing all numbers in b's group to get b
Alternatively, XOR (a xor b) with a gets you b.
*/
/*
-x == ~x + 1 (this is a result of two’s complement)

When lowest order bit is 1’s position:

Consider a bit series for x that ends in 1. ~x will end in 0, therefore ~x+1 ends in 1
Consider a bit series for x that ends in 0. ~x will end in 1, therefore ~x+1 will carry a bit and end in 0.
This establishes that the lowest order bit of x&(-x) will always match the lowest order bit of x.

What about when lowest order bit is higher order bit?

Consider a bit series for x that ends in 1. There is no carrying when calculating -x==~x+1, therefore higher order bits will be inverted between x & -x therefore AND is zero for all but 1’s position.
Consider a bit series for x that ends in 0. As we calculate -x==~x+1 the carrying bit will change some number of 1’s to 0’s until the carry bit hits a 0. All these 0’s will force those the results of those bit AND’s to be 0. As for the 0 that gets hit by the carry bit and turned to a 1 it will AND with a 1 at that position in the original value of x. Anything above that bit will be equivalent to x&~x
example:
x=122 (base 10)
x=01111010
~x=10000101
~x+1=10000110
x&(~x+1)=00000010
*/
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};
