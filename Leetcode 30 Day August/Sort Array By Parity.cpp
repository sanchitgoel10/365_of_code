class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int i=0;
        int j=A.size()-1;
        while(i<j){
            if(A[i]%2==0){       //even first
                i++;
            }
            else{
                if(A[j]%2==1){     //both odd
                    j--;
                }
                if(A[j]%2==0){            //odd even
                    swap(A[i],A[j]);
                    i++,j--;
                }
            }
        }
        return A;
    }
};