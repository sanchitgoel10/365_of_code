/*
Find all the triplets in an rating array that satisfiy i<j<k and rating[i]<rating[j]<rating[k] or i<j<k and rating[i]>rating[j]>rating[k].

Explanation
Because n is small (only 200), an O(n^3) algorithm is ok. But it is easy to optimize the algorithm to O(n^2). For each rating[j], the number of triplets satisfying i<j<k and rating[i]<rating[j]<rating[k] is cnt(i<j, rating[i]<rating[j]) * cnt(j<k, rating[j]<rating[k]), and the number of triplets satisfying i<j<k and rating[i]>rating[j]>rating[k] is cnt(i<j, rating[i]>rating[j]) * cnt(j<k, rating[j]>rating[k]).
*/
C++ Solution
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int leftLarger = 0, leftSmaller = 0, rightLarger = 0, rightSmaller = 0;
            for (int j = 0; j < i; j++)
                if (rating[j] < rating[i])
                    leftSmaller++;
                else if (rating[j] > rating[i])
                    leftLarger++;
            for (int j = i + 1; j < n; j++)
                if (rating[j] < rating[i])
                    rightSmaller++;
                else if (rating[j] > rating[i])
                    rightLarger++;
            ans += leftSmaller * rightLarger + leftLarger * rightSmaller;
        }
        return ans;
    }
};