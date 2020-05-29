class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> in(num,0);
        vector<int> adj[num];
        for(auto i:pre){
            in[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        int ind=0;
        queue<int> q;
        for(int i=0;i<num;i++){
            if(in[i]==0){
                q.push(i);
                ind++;
            }
        }
        
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto i:adj[curr]){   //time kam use karne ke liye adj list banani padi
                if(--in[i]==0){
                    q.push(i);
                    ind++;
                }
            }
        }
        return ind==num?1:0;
    }
};