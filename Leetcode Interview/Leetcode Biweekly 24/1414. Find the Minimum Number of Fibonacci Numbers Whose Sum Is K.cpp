/*
We greedily subtract the biggest Fibonacci number x from k,
and recursive to find the result for k - x.
Then f(k) = f(k - x) + 1


Intuition II
The feeling seems good,
but what if the interviewer ask for a prove?

Well, I can figure this out.
Will the interviewer really expect the prove during 45min?

If the interviewer doesn't request it,
can I ask them for the prove?

If they cannot even give me a prove,
why the hell they ask me this question?

Weak application for the company!


Prove
Among all resolution with the minimum number of Fibonacci numbers,
we are find the lexicographically largest one.
In this resolution, we must:

uses each Fibonacci number at most once
never uses two consecutive Fibonacci numbers
First
In best resolution of k,
there is no two adjacent Fibonacci number.

This can be easily obtained,
because if we have fibo[i] + fibo[i+1],
we can have fibo[i+2] instead,
and we save one number.


Second
In one of the best resolution of k,
there can be no duplicate Fibonacci number.
Assume we have two fibo[i].

I noticed that fibo[i] * 2 = fibo[i - 2] + fibo[i + 1]
For example
Assuming fibo = [1,2,3,5,8,13,21,33]
2 + 2 = 1 + 3
3 + 3 = 1 + 5
5 + 5 = 2 + 8
8 + 8 = 3 + 13
13 + 13 = 5 + 21
21 + 21 = 8 + 33

If we have two same number,
we can always transfor to two different number.

Don't need worrying about if this process will cause other duplicate.
We clear the duplicate from the small to big.


Third
If no dup, no adjacent, we must take the biggest.
fibo[0] + fibo[2] + fibo[4] + ... + fibo[2n] = fibo[2n + 1] - 1
fibo[1] + fibo[3] + fibo[5] + .... + fibo[2n-1] = fibo[2n] - 1

For example:
1 = 2 - 1
1 + 3 = 5 - 1
1 + 3 + 8 = 13 - 1
1 + 3 + 8 + 21 = 34 - 1

2 = 3 - 1
2 + 5 = 8 - 1
2 + 5 + 13 = 21 - 1
2 + 5 + 13 + 34 = 55 - 1

So if k >= fibo[2n],
and we don't take fibo[2n]
the rest sum of every two Fibo numbers can only reach a maximum fibo[2n] - 1

The same for the case where k >= fibo[2n + 1]


@OneSheep supported a supplement explanation here:
If we use [1,1,2,3,5,8,13,21,34].

f[2n+1]
=f[2n]+f[2n-1]
=f[2n]+f[2n-2]+f[2n-3]
=f[2n]+f[2n-2]+...+f[6]+f[5]
=...+f[6]+f[4]+f[3]
=...+f[6]+f[4]+f[2]+f[1]
=...+f[6]+f[4]+f[2]+f[0] (because f[0]==f[1])

f[2n]
=f[2n-1]+f[2n-2]
=f[2n-1]+f[2n-3]+f[2n-4]
=...+f[5]+f[4]
=...+f[5]+f[3]+f[2]
=...+f[5]+f[3]+f[1]+f[0]
*/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int f1 = 0, f2 = 1;
        while (f2 <= k) {
            swap(f1, f2);
            f2 += f1;
        }
        return 1 + (k == f1 ? 0 : findMinFibonacciNumbers(k - f1));
    }
};