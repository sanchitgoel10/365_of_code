class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > ans;
        int n=A.size();
        int m=B.size();
        if(n==0||m==0)return ans;
        
        int i=0,j=0;
        while(i<n&&j<m){
            if(B[j][0]>A[i][1]){
                i++;
            }else if(A[i][0]>B[j][1]){
                j++;
            }else{
                int st=max(A[i][0],B[j][0]);
                int end=min(A[i][1],B[j][1]);
                ans.push_back({st,end});
                if(A[i][1]<B[j][1])i++;
                else if(A[i][1]>B[j][1])j++;
                else{
                    i++;j++;
                }
            }
        }
        return ans;
    }
};