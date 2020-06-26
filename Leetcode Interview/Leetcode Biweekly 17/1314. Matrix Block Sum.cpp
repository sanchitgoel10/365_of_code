/*mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix is actually a square centered at (i,j) and has side length of 2K+1. if r < 0 or r >= m, c < 0 or c >= n, it could become a rectangle or a smaller square.

Below is an example of a 3 * 3 matrix. K = 1 in this case.


So, how can we find a uniform way to calculate the sum of the yellow cells? This is when I remembered prefix sum. Generating a prefix sum array for a 1D array is quite straight forward. In a 2D array, the calculation is slightly different. The value of prefix_sum[i][j] is the sum of the values in the rectangle where (i,j) and (0,0) are the two opposite corners. This will help us avoid most of the repeating calculation.

Having calculated the prefix sum matrix, our problem becomes prefix_sum[i+K][j+K] minus the blue squares in the below graph. For example, answer[2][2] = prefix_sum[2][2] - prefix_sum[0][2]-prefix_sum[2][0] + prefix_sum[0][0].

*/
class Solution {
public: 
    int sizeX, sizeY;
    int extractSum(int i, int j, const vector<vector<int> >& sum) {
        if (i < 0 || j < 0) return 0;
        if (i >= sizeX) i = sizeX - 1;
        if (j >= sizeY) j = sizeY - 1;
        return sum[i][j];
    }
        
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        sizeX = mat.size();
        sizeY = mat[0].size();
        
        vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
        // Calculate prefix matrix 
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
            }
        }
        
        // Use prefix matrix to calculate our sum
        vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);
            }
        }
        
        return ans;
    }
};

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> prefix_sum = prefixSum(mat);
        vector<vector<int>> answer = prefix_sum;
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                int upper_i = ((i+K) >= mat.size()) ? (mat.size()-1) : (i+K);
                int upper_j = ((j+K) >= mat[0].size()) ? (mat[0].size()-1) : (j+K);
                
                int lower_i = ((i-K) <= 0 ) ? 0 : (i-K);
                int lower_j = ((j-K) <= 0 ) ? 0 : (j-K);
            
                
                answer[i][j] = prefix_sum[upper_i][upper_j] - ((lower_i == 0) ? 0 : prefix_sum[lower_i-1][upper_j]) - ((lower_j == 0) ? 0 : prefix_sum[upper_i][lower_j-1]) + ((lower_i == 0) || (lower_j == 0)  ? 0 : prefix_sum[lower_i-1][lower_j-1]);
            }
        }
    
        
        return answer;
        
    }
    
    vector<vector<int>> prefixSum(vector<vector<int>>& mat) {
        vector<vector<int>> prefix_sum = mat;
        
        for (int i = 0; i < mat.size(); i++) {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                sum = sum + mat[i][j];
                if (i > 0) {
                    prefix_sum[i][j] = sum + prefix_sum[i-1][j];
                } else {
                    prefix_sum[i][j] = sum;   
                }
            }
        }
        
        return prefix_sum;
    }

};