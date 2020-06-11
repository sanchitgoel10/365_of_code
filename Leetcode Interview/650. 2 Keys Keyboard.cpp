/*
NO DP
It take 2 ops to double, 3 ops to triple, ...
if n % 2 == 0, then f(n) = f(n/2) + 2
if n % 3 == 0, then f(n) = f(n/3) + 3
2 * 2 = 2 + 2; 2 * 3 > 2 + 3; 4 * 4 > 4 + 4; so it is always better to divide whenever possible.
now it became a problem for finding all possible factors;
We can break the total sequence of operations into groups that take the form "[copy][some number of pastes]" In K operations of this group, the length of the string is multiplied by K.

Now, suppose N can be written as N = d_1 * d_2 * ... * d_k. By the above reasoning, N "A"s can be written on the tape in d_1 + d_2 + ... + d_k operations. If any of the d_i are composite, say d_i = p*q (with p>1, q>1), then we could write it in p + q instead of p*q operations by breaking up this divisor.

For example, if we make 15 with 15 operations, we could instead make it with 3 operations to get AAA then another 5 operations. Also, we should justify that p+q <= p*q (because (p-1)(q-1) is positive), so we indeed do get savings by breaking up this product.
*/
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};


