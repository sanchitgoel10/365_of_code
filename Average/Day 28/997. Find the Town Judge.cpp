#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int*arr = new int[N+1]();
        int*carr = new int[N+1]();
        
        for(auto i:trust){
            arr[i[1]]++;
            carr[i[0]]++;
        }
        int c=0;
        int ans=-1;
        
        for(int i=1;i<=N;i++){
            if(arr[i]==N-1&&c==1&&carr[i]==0){
                return -1;
            }
            if(arr[i]==N-1&&carr[i]==0){
                c=1;
                ans=i;
            }
        }
        return ans;
    }
};