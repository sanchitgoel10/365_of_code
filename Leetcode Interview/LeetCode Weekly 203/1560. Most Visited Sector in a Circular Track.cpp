/*
Intuition
We only need to care the start point and the end point.


Explanation
If start <= end, return the range [start, end].
If end < start, return the range [1, end] + range [start, n].
*/
  vector<int> mostVisited(int n, vector<int>& A) {
        vector<int> res;
        for (int i = A[0]; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        if (res.size() > 0) return res;
        for (int i = 1; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        for (int i = A[0]; i <= n; ++i)
            res.push_back(i);
        return res;
    }


//Prefix sum

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> vec(n+2,0);
        vec[rounds[0]]++;
        vec[rounds[1]+1]--;
        for(int i=2;i<rounds.size();i++){
            int l=rounds[i-1];
            int r=rounds[i];
            vec[l+1]+=1;
            vec[r+1]-=1;
        }
      
        for(int i=1;i<=(n+1);i++){
            vec[i]+=vec[i-1];
        }
        
        vector<int> ans;
        int an=0;
        for(int i=1;i<=n;i++){
            if(vec[i]>an){
                ans.clear();
                an=vec[i];
                ans.push_back(i);
            }
            else if(vec[i]==an){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};