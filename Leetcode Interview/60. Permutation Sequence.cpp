/*
This problem is recursive like dynamic programming.
Kth Permutation sequence can be formed by choosing the 1st digit and then the rest of the digits one by one.
Visually:
1 + (permutations of rest of digits)
2 + (permutations of ...)
so on...

For N=3,
we have the permutations:
1|2,3
1|3,2
2|1,3
2|3,1
3|1,2
3|2,1

I put a bar "|" to separate first digit from the rest of digits.
There are a total of N! = 3! = 6 perms. Each 1st digit is "attached" to (n-1)! =2! = 2 permutations formed by rest of digits.
Thus , to choose 1st digit, simply calculate (k-1) / (n-1)! and use it to index into an array of digits 1,2,3,
Once 1st digit is chosen, we choose 2nd and so on recursively.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        --k;  //index  0 based karna hai
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];                   //for further calculations, calculate karke dekh tabhi ayega smj
            res.push_back(nums[j]);
            nums.erase(nums.begin() + j);    //O(n) operation
        }
        return res;
    }
};