/*Intuition
Solve it with a greed algorithme.

Initial N empty string.
For each column,
add the character to each row,
and check if all rows are still sorted.

If not, we have to delete this column.
*/

class Solution {
public:
    
    bool check(vector<string>&temp){
        for(int i=1;i<temp.size();i++){
            if(temp[i]<temp[i-1])return 0;
        }
        return 1;
    }
    
    int minDeletionSize(vector<string>& A) {
        int r=A.size();
        if(r==0)return 0;
        int c=A[0].size();
        int ans=0;
        vector<string> lol(r);
        
        for(int i=0;i<c;i++){
            vector<string> temp=lol;
            for(int j=0;j<r;j++){
                temp[j]+=A[j][i];
            }
            if(check(temp)){
                lol=temp;
            }else{
                ans++;
            }
        }
        return ans;
    }
};