class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        if(n==0)return 1;
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int curr=q.front();
                q.pop();
                for(auto i:rooms[curr]){
                    if(vis[i])continue;
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        bool ans=1;
        for(auto b:vis){
            if(!b){
                ans=0;
                break;
            }
        }
        return ans;
    }
};