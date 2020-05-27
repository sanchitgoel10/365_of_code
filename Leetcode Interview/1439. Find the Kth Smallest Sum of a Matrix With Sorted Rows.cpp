/*
let's define mat and k like this:
mat = [
[1,10,10],
[1,4,5],
[2,3,6],
]
k = 3

when we make numbers by mat[0] and mat[1],
we can get temp = [1 + 1, 1 + 4, 1 + 5, 10 + 1, 10 + 4, 10 + 5, 10 + 1, 10 + 4, 10 + 5]
and we sort it , so it become [2,5,6,11,11,14,14,15,15]
then we make finnal answer, by this temp and mat[2]

since the max(mat.size()) = 40, max(mat[i].size()) = 40
in the worst case, the ans vector's size will become 40^40, this is a super huge number

one idea is to cut the temp vector
back to the case,
after caculating mat[0] and mat[1], we get
temp = [2,5,6,11,11,14,14,15,15]
mat[2] = [2,3,6]

here is the point if you notice that the k-th number in answer will never use to calculate the k-th number in temp!!
so we juct cut the temp's size and can calculate it
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row(mat[0]);
        for(int i = 1; i < mat.size(); ++i) {
            vector<int> nr;  // next row
            for(int j = 0; j < mat[i].size(); ++j)                          
                for(auto pathSum : row) 
                    nr.push_back(mat[i][j] + pathSum); // all possible path ends at [i,j] by far                    
                            
            sort(nr.begin(), nr.end());            
            nr.resize( min(k, int(nr.size())) );
            row=move(nr);                   
        }        
        return row[k-1];
    }
};