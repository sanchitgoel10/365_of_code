Assume B[i][j] = A[i] | A[i+1] | ... | A[j]
Hash set cur stores all wise B[0][i], B[1][i], B[2][i], B[i][i].

When we handle the A[i+1], we want to update cur
So we need operate bitwise OR on all elements in cur.
Also we need to add A[i+1] to cur.

In each turn, we add all elements in cur to res.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur, cur2;
        //cur.insert(0);
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            cur = cur2;
            for (int j: cur) res.insert(j);
        }
        return res.size();
    }
};