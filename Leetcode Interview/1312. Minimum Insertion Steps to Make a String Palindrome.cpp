/*
Let's imagine matching the characters of the string like a palindrome, from the begining and the end with 2 pointers i and j.
We may encounter 2 scenarios:

The character at i matches character at j.
The characters don't match each other
In case of 1 we just increase the pointer i and decrease the pointer j, i++ and j-- respectively.

In the second case we have 2 options:

Insert one character at j to match the character at i.
Or

Insert one character at i to match the character at j.
Since we are not actually adding the characters in the string but just calculating the cost,
In case 1 we increase the pointer i by 1 and j stays as it is, as we still need a character to match at j
and in case 2 we decrease the pointer j by 1 and i stays as it is, as we still need a character to match at i.
both the cases adds cost 1 since we are inserting a letter.

We can then use these two different pairs of new i and j values (i+1, j and i, j-1) to again repeat the process and use the minimum result of these as our result for current pair of i, j.
We can see that this is recursive and thus we can use recursion with caching to store the repeated values.

Solution (Memoization)
*/
class Solution {
public:
    vector<vector<int>> memo;
    int dp(string &s,int i,int j)
    {
        if(i>=j)							//Base case.
            return 0;
        if(memo[i][j]!=-1)					//Check if we have already calculated the value for the pair `i` and `j`.
            return memo[i][j];
        return memo[i][j]=s[i]==s[j]?dp(s,i+1,j-1):1+min(dp(s,i+1,j),dp(s,i,j-1));		//Recursion as mentioned above.
    }
    int minInsertions(string s) 
    {
        memo.resize(s.length(),vector<int>(s.length(),-1));
        return dp(s,0,s.length()-1);
    }
};
/*
Split the string s into to two parts,
and we try to make them symmetrical by adding letters.

The more common symmetrical subsequence they have,
the less letters we need to add.

Now we change the problem to find the length of longest common sequence.
This is a typical dynamic problem.


Explanation
Step1.
Initialize dp[n+1][n+1],
wheredp[i][j] means the length of longest common sequence between
i first letters in s1 and j first letters in s2.

Step2.
Find the the longest common sequence between s1 and s2,
where s1 = s and s2 = reversed(s)

Step3.
return n - dp[n][n]


Complexity
Time O(N^2)
Space O(N^2)
C++:

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = s[i] == s[n - 1 - j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        return n - dp[n][n];
    }