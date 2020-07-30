/*
For every integer N, F(N) = (total number of positive integers <= N which are divisible by a or b or c.).
image

The left-top circle stands for numbers <= N that are divisible by a
others the same idea, and the intersection of two/three circles is the total number of positive integers <= N which are divisible by theleast common multiple of them.
F(N) = a + b + c - a ∩ c - a ∩ b - b ∩ c + a ∩ b ∩ c
F(N) = N/a + N/b + N/c - N/lcm(a, c) - N/lcm(a, b) - N/lcm(b, c) + N/lcm(a, b, c)(lcm = least common multiple)
Find the least integer N that satisfies the condition F(N) >= K
*/
class Solution {
public:    
   int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k) 
                lo = mid + 1;
            else
			   //the condition: F(N) >= k
                hi = mid;
        }
        return lo;
    }
};