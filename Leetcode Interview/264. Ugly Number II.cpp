/*
Let me try to explain this using an example. Let's say we have the first 3 ugly numbers 1, 2, 3. What would be the next number? Given the definition, the next number has to be the the smallest number among 2*(1,2,3), 3*(1,2,3), 5*(1,2,3). Obviously, the smallest number is 2 * 1 = 2. But wait, 2 is already in there. So precisely speaking, the next number has to be the the smallest number among all the existing numbers multiplied by 2, 3,5 that isn't in the list already. Now, we can traverse all numbers and maintain a hashset if we want, but it would become O(N^2). Good news is that we can solve this in a DP-like approach. First, we assume there is only one number in the list, which is 1. The next number is Min(2 * 1, 3 * 1, 5 * 1)=2 and it is not in the list. Because we have already considered 2*1 (we move the pointer to its next position, which is 2), now we only need to consider 2 * 2, 3 * 1, 5 * 1 in the next iteration. This way, we don't have to worry about finding a number that is already in the list.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return 1; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};