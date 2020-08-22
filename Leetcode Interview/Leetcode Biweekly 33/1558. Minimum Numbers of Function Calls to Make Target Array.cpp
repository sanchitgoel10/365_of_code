/*
(Minimum number of operations) = minimum((number of +1 operations) + (number of x2 operations))

number of x2 operations = (highest set bit in binary representation) because each x2 operation shifts the binary digit to left, hence highest set bit will be number of x2 operations we will have to perform. By only performing (highest set bit) number of operations, we reuse x2 operation across all nums.

number of +1 operations = (number of 1s in the binary representation of each number) because each 1 in binary representation is introduced by +1 operation.
*/
class Solution {
    public int minOperations(int[] nums) {
        int addOneOperations = 0; // +1 operations
        int highestSetBit = 0; // x2 operations
        for (int bit = 0; bit <= 30; ++bit) {
            for (int num : nums) {
                if ((num & (1 << bit)) != 0) {
                    ++addOneOperations;
                    highestSetBit = bit;
                }
            }
        }
        return addOneOperations + highestSetBit; // (+1 operations) + (x2 operations)
    }
}