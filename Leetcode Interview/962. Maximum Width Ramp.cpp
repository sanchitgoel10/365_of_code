/*Stack based.

Keep a stack of decreasing order elements.

Let’s take an example of : [6,0,8,2,1,5]

Decreasing order stack : 6,0.

There’s no point of adding 8 to stack.
Since for any element on the right for which 8 would be a part of solution (i.e. 8 is on the left end of ramp) , 0 can also be the left end for that ramp and provides a larger length of ramp since index of 0 is less than that of 8. This assures as that 8 will never be the left end of our largest ramp.

Similar explanation applies for 2,1 and 5.

Now after we have stack, start iterating the array from end considering :

Current element to be the right end of ramp and top element of the stack to be left end of the ramp. If stack’s top element satisfies the condition, we have a candidate ramp.

The trick here is: Now we can pop that element out of the stack. Why?
Let’s say we were right now at index j of the array and stack’s top is at index i.

So ramp is i..j.

As we are iterating backwards in the array, the next possible right end of the ramp will be j-1. Even if formes a ramp with i, it’s length would be shorter than our current ramp (i.e. j-i).

So, no point in keeping in 0 in stack now.

Keep popping elements off the stack whenever we have a candidate ramp. Since the current candidate ramp is the best ramp considering the stack’s top element to the left end of that ramp
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || A[s.top()] > A[i])
                s.push(i);
        for (int i = n - 1; i >=0 ; --i)
            while (!s.empty() && A[s.top()] <= A[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};