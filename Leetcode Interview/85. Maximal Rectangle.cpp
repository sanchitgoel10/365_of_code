/* we start from the first row, and move downward;
 * height[i] record the current number of countinous '1' in column i;
 * left[i] record the left most index j which satisfies that for any index k from j to  i, height[k] >= height[i];
 * right[i] record the right most index j which satifies that for any index k from i to  j, height[k] >= height[i];
 * by understanding the definition, we can easily figure out we need to update maxArea with value (height[i] * (right[i] - left[i] + 1));
 * 

 height means from top to this position, there are how many '1'
left means at current position, what is the index of left bound of the rectangle with height[j]. 0 means at this position, no rectangle.
right means the right bound index of this rectangle. 'n' means no rectangle.

matrix
0 0 0 1 0 0 0
0 0 1 1 1 0 0
0 1 1 1 1 1 0

height
0 0 0 1 0 0 0
0 0 1 2 1 0 0
0 1 2 3 2 1 0

left
0 0 0 3 0 0 0
0 0 2 3 2 0 0
0 1 2 3 2 1 0

right
7 7 7 4 7 7 7
7 7 5 4 5 7 7
7 6 5 4 5 4 7

result
0 0 0 1 0 0 0
0 0 3 2 3 0 0
0 5 6 3 6 5 0
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {    //largest histogram
        int n=heights.size(); 
        if(n==0)return 0;
        vector<int> left(n),right(n); // idx of the first bar the left that is lower than current//// idx of the first bar the right that is lower than current
        left[0]=-1;
        right[n-1]=n;
        for(int i=1;i<n;i++){
            int p=i-1;
            while(p>=0&&heights[p]>=heights[i]){
                p=left[p];
            }
            left[i]=p;
        }
        for(int i=n-2;i>=0;i--){
           int p=i+1;
            while(p<n&&heights[p]>=heights[i]){
                p=right[p];
            }
            right[i]=p;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)return 0;
        int m=matrix[0].size();
        vector<int> h(m,0);
        int max_a=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')h[j]++;
                else h[j]=0;
            }
            max_a=max(max_a,largestRectangleArea(h));
        }
        return max_a;
    }
};


