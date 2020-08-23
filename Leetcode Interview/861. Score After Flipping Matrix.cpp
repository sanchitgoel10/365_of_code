/*
First of all, after looking at this question, the first thing which comes in mind is simulation. But wait, the question doesn't state any restrictions, because you can toggle as many rows and columns as you want and however times as you want. Then it means, its practically impossible to simulate all situations. So, what do we do next. Lets understand the structure of the binary number.
A binary number, for example is something like

01010
Now, think for a moment, how can we maximize it? You guessed it right probably, by maximizing the number of 1's, which are as left as possible. Now, see below example,

0111 and 1000
The first number is 7 and the second is 8. So, overall we decreased the number of 1's, but the value has increased as we tried to get the 1 as left as possible. Now you got it? Exactly, if the first bit is zero, flip the binary. So, for our problem, we use this property (call it property 1).First thing which we will do is try to flip all rows, whose first column is zero.
Great, now lets look at another optimization. For a particular column, it would be great if we could maximize the number of 1's. Why? Because, if you think carefully, all are at same bit position. Hence, if the number of1's increase, the total sum would increase.
Hence, we use this second property(call it property 2). We scan through each column, and check if the number of 1's in that column are less than or equal to half the number of rows. If yes, then we flip the column to maximize the number of 1's in that column. However, be careful to do this for all columns except first, else you would break the first property.
That's it. Now, I hope you would easily understand the below unoptimized code which is written in C++.
*/
class Solution {
public:
    void flipRow(vector<vector<int>>& A,int row,int n){
        for(int j = 0;j < n;j++){
            if(A[row][j] == 0)
                A[row][j] = 1;
            else
                A[row][j] = 0;
        }
    }
    
    void flipCol(vector<vector<int>>& A,int col,int m){
        for(int i = 0;i < m;i++){
            if(A[i][col] == 0)
                A[i][col] = 1;
            else
                A[i][col] = 0;
        }
    }
    
    
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<int> col(n,0);
        
        for(int i = 0;i < m;i++){
            if(A[i][0] == 0)
                flipRow(A,i,n);
            for(int j = 0;j < n;j++){
                if(A[i][j] == 1)
                    col[j]++;
            }
        }
        
        for(int j = 0;j < n;j++){
            if(col[j] <= m/2)
                flipCol(A,j,m);
        }
        
        int result = 0,sum;
        for(vector<int> v : A){
            sum = 0;
            for(int j = v.size()-1;j >= 0 ;j--){
                if(v[j] == 1)
                    sum += pow(2,v.size()-1-j);
            }
            result += sum;
        }
        
        return result;
    }
};
/*
But, if you carefully observe, we are not required to manipulate the matrix. By this, we can avoid unnecessary calculations.

Now, see the below Java code. I will explain it later.
*/
class Solution {
    public int matrixScore(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        int result = 0;
        
        result += (1 << (n-1))*m;
        
        for(int j = 1;j < n;j++){
            int same = 0;
            for(int i = 0;i < m;i++){
                if(A[i][0] == A[i][j])
                    same++;
            }
            result += (1 << (n-1-j))*Math.max(same,m-same);
        }
        
        return result;
    }
}
/*
Firstly, we are sure to set all the first bits of all binary numbers as 1. So, first lets calculate the value for them. This is what is done in

result += (1 << (n-1))*m;
Next, we start from first column and check the number of values which are same(0 or 1) for each row, with the first column element. Why? Because if they are both 0, then would be naturally flipped to 1(from property 1). If they are 1, then the row would naturally wouldn't be flipped(again from property 1). Hence, intuitively, you can consider the variable same to store the maximum number of 1's we have currently.
Now, as said before, we need to maximize same. intuitively, if same is the number of 1's, m-same is the number of 0's. We take the maximum of two to maximize the number of 1's, which will done by either keeping the column unflipped(if currently, number of 1's are more than number of 0's) or by flipping it as required.
Finally, we add the value for those bit positions for the 1's in this line
result += (1 << (n-1-j))*Math.max(same,m-same);
and finally return the result.
*/