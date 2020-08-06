class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        vector<int> dpl(n,0),dpr(n,0);
        for(int i=1;i<n;i++){
            if(A[i]>A[i-1]){
                dpl[i]=dpl[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(A[i]>A[i+1]){
                dpr[i]=dpr[i+1]+1;
            }
        }
        
        int ans=-1;
        for(int i=0;i<n;i++){
            if(dpl[i]&&dpr[i]){
                ans=max(ans,dpl[i]+dpr[i]+1);
            }
        }
        return ans>=3?ans:0;
    }
};

//One pass and O(1)

int longestMountain(vector<int>& A) {
        int maxMnt = 0;
    
        int i = 1;
        while (i < A.size()) {
            while(i < A.size() && A[i-1] == A[i])
                ++i;
            
            int up = 0;
            while(i < A.size() && A[i-1] < A[i]) {
                ++up;
                ++i;
            }
            
            int down = 0;
            while(i < A.size() && A[i-1] > A[i]) {
                ++down;
                ++i;
            }
            
            if (up > 0 && down > 0)  
                maxMnt = max(maxMnt, up+down+1);
            
        }
        
        return maxMnt;
    }