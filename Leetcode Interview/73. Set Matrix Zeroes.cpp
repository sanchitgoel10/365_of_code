/*
The inefficiency in the second approach is that we might be repeatedly setting a row or column even if it was set to zero already. We can avoid this by postponing the step of setting a row or a column to zeroes.

We can rather use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero. This means for every cell instead of going to M+NM+N cells and setting it to zero we just set the flag in two cells.

if cell[i][j] == 0 {
    cell[i][0] = 0
    cell[0][j] = 0
}
These flags are used later to update the matrix. If the first cell of a row is set to zero this means the row should be marked zero. If the first cell of a column is set to zero this means the column should be marked zero.

I think what Chen tries to do is to store information at the first element of each columns and rows. If a column contains a 0, it's first element will be 0. Same for rows. However, both first column and first row use matrix[0][0] which is problematic so she creates another variable for first column, col0.
Finally, start setting zeros from the bottom right corner.
brilliant! cheers!
*/
void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }