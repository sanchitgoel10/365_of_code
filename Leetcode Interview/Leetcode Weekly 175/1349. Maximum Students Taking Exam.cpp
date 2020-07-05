Bitmasking DP rarely appears in weekly contests. This tutorial will introduce my own perspective of bitmasking DP as well as several coding tricks when dealing with bitmasking problems. I will also give my solution to this problem at the end of this tutorial.

What is bitmasking? Bitmasking is something related to bit and mask. For the bit part, everything is encoded as a single bit, so the whole state can be encoded as a group of bits, i.e. a binary number. For the mask part, we use 0/1 to represent the state of something. In most cases, 1 stands for the valid state while 0 stands for the invalid state.

Let us consider an example. There are 4 cards on the table and I am going to choose several of them. We can encode the 4 cards as 4 bits. Say, if we choose cards 0, 1 and 3, we will use the binary number "1011" to represent the state. If we choose card 2, we will use the binary number "0100" then. The bits on the right represent cards with smaller id.

As we all know, integers are stored as binary numbers in the memory but appear as decimal numbers when we are coding. As a result, we tend to use a decimal number instead of a binary number to represent a state. In the previous example, we would use "11" and "4" instead of "1011" and "0100".

When doing Bitmasking DP, we are always handling problems like "what is the i-th bit in the state" or "what is the number of valid bits in a state". These problems can be very complicated if we do not handle them properly. I will show some coding tricks below which we can make use of and solve this problem.

We can use (x >> i) & 1 to get i-th bit in state x, where >> is the right shift operation. If we are doing this in an if statement (i.e. to check whether the i-th bit is 1), we can also use x & (1 << i), where the << is the left shift operation.

We can use (x & y) == x to check if x is a subset of y. The subset means every state in x could be 1 only if the corresponding state in y is 1.

We can use (x & (x >> 1)) == 0 to check if there are no adjancent valid states in x.

Now we can come to the problem. We can use a bitmask of n bits to represent the validity of each row in the classroom. The i-th bit is 1 if and only if the i-th seat is not broken. For the first example in this problem, the bitmasks will be "010010", "100001" and "010010". When we arrange the students to seat in this row, we can also use n bits to represent the students. The i-th bit is 1 if and only if the i-th seat is occupied by a student. We should notice that n bits representing students must be a subset of n bits representing seats.

We denote dp[i][mask] as the maximum number of students for the first i rows while the students in the i-th row follow the masking mask. There should be no adjancent valid states in mask. The transition function is:

dp[i][mask] = max(dp[i - 1][mask']) + number of valid bits(mask)
where mask' is the masking for the (i-1)-th row. To prevent students from cheating, the following equation must hold:

(mask & (mask' >> 1)) == 0, there should be no students in the upper left position for every student.

((mask >> 1) & mask') == 0, there should be no students in the upper right position for every student.

If these two equation holds and dp[i - 1][mask'] itself is valid, we could then transit from dp[i - 1][mask'] to dp[i][mask] according to the transition function.

And the last question is, how can we compute the number of valid bits in a masking efficiently? In C++, we can simply use the built-in function __builtin_popcount(mask). For other programming languages, we can pre-compute by using count[i] = count[i/2] + (i % 2 == 1) and store them in an array.

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> validity; // the validity of each row in the classroom
        for (int i = 0; i < m; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
				// the j-th bit is 1 if and only if the j-th seat is not broken
				// here the 0th bit is the most significant bit
                cur = cur * 2 + (seats[i][j] == '.');
            }
            validity.push_back(cur);
        }
		
		// all the f states are set -1 as invalid states in the beginning
		// here f[i][mask] represents the first i-1 rows to handle corner cases
        vector<vector<int>> f(m + 1, vector<int>(1 << n, -1));
		// f[0][0] is a valid state
		// think of a virtual row in the front and no students are sitting in that row
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            int valid = validity[i - 1];
			// the interval [0, 1 << n) includes all the n-bit states for a row of students
			// please note that state 0 represents no student sitting in this row
			// which is always a valid state
            for (int j = 0; j < (1 << n); ++j) {
				// (j & valid) == j: check if j is a subset of valid
				// !(j & (j >> 1)): check if there is no adjancent students in the row
                if ((j & valid) == j && !(j & (j >> 1))) {
					// f[i][j] may transit from f[i -1][k]
                    for (int k = 0; k < (1 << n); ++k) {
						// !(j & (k >> 1)): no students in the upper left positions
						// !((j >> 1) & k): no students in the upper right positions
						// f[i - 1][k] != -1: the previous state is valid
                        if (!(j & (k >> 1)) && !((j >> 1) & k) && f[i - 1][k] != -1) {
                            f[i][j] = max(f[i][j], f[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }
        
		// the answer is the maximum among all f[m][mask]
        return *max_element(f[m].begin(), f[m].end());
    }
};