/*
Observation:
Let's use Example 1 for illustration:
[[0,0,1],[1,1,0],[1,0,0]]
tailing zero counts are: [0, 1, 2] (starting status)
The desired final goal is: [2,1, 0] (ending status)

So, the problems is converted to find the minimal ajacent swaping from starting status to ending status:
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> t(n); //t[i]: tailing zero count for i-th row        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j = n;--j>=0 && !grid[i][j]; )  count++;                
            t[i] = count;
        }
        int ans = 0;        
        for(int i=0;i<t.size();i++){
            int k = i;
            int req = n-1 - i; // desired tailing zero count
            while(k<n && t[k]<req) k++; // greedily find first swaping candidate
            if(k==n) return -1;
            ans += k-i;
            
            while(k>i){ // simulate swaping operation of two adjacent rows
                t[k] = t[k-1];
                k--;
            }
        }    
        
        return ans;
    }
};