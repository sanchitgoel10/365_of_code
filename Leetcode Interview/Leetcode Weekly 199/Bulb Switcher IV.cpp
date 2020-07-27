/*
Key idea
Flip is a must when current status of the bulbs and target status are not same.

Initially all bulbs are at 0 and when a bulb at index i is flipped, everything that comes after that gets flipped. So it only makes sense to keep getting the status of the bulbs correct from left to right.

We will keep track of the status of the bulbs as we make flips.

Initially all bulbs are 0, so say status = 0.
Bulb 0 is 0 initially.

If we want it to be 0, we don't have to make a flip.
If we want it to be 1, we must make a flip. This will change the status of remaining bulbs and they will be ON i.e. 1, so we will also make status as 1.
Whenever we see the status to be different from what the target is, we must make a flip and this will also change the status of remaining bulbs.
*/
class Solution {
public:
    int minFlips(string target) {
        int n = target.size();                          // Total bulbs.
        int flips = 0;                                  // Final answer.
        char status = '0';                              // This stores the status of bulbs that are
                                                        // ahead of current index `i`.
        for (int i=0; i<n; i++) {                       // For each bulb =
            if (status != target[i]) {                  // If what we want is different from what
                                                        // it is at this moment, make a flip.
                flips++;                                // We made a flip.
                status = status == '0' ?  '1' : '0';    // Now status of remaining
                                                        // bulbs have changed.
            }
        }
        return flips; // Awesome, return the answer now.
    }
};