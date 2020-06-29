class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto q:queries){
            if(q[0]==0){
                ans.push_back(pre[q[1]]);
            }else{
                ans.push_back(pre[q[1]]^pre[q[0]-1]);
            }
        }
        return ans;
    }
};