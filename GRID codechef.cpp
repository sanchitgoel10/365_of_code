#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char mat[n][n];
        int ans[n][n];      // array of max horizontal allowance 
        int ansb[n][n];     // array of max vertical allowance
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='.'){
                    ans[i][j]=1;
                    ansb[i][j]=1;
                }
                else{
                    ans[i][j]=0;
                    ansb[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=n-2;j>=0;j--){
                if(mat[i][j]==mat[i][j+1] && mat[i][j]=='.'){
                    ans[i][j]=ans[i][j+1]+1;
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==mat[i+1][j] && mat[i][j]=='.'){
                    ansb[i][j]=ansb[i+1][j]+1;
                }
            }
        }
        int res=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ansb[i][j]==(n-i) && ans[i][j]==(n-j)){    // 1st cond= if i can reach there from down without stone
                    res++;                                    //2nd cond =  if from there i can reach east side wiithout rock
                }
            }
        }
        
        cout<<res<<endl;
        
        
    }
    return 0;
}