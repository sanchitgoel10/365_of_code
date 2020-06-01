/*let p(n) be the probability that the n-th seat is taken before n-th passenger chooses.
If n-1st seat is not taken before n-1st passenger chooses, then the probability that the n-th seat will be taken is 0.
Otherwise, n-1st passenger will choose between two seats (n-th seat and some other seat that's not his own), so he has the probability of 1/2 of taking the n-th seat.
*/
p(n) = 0 * (1 - p(n-1)) + 1/2
p(n) = 1/2

Base case: p(1) = 0.

We are asked about the probability that the n-th seat is not taken, so the solution is 1 - p(n).



class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return (double)1;
        return (double)0.5;
    }
};