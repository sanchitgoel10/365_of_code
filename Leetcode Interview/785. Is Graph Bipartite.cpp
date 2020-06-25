class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==0)return 1;
        unordered_set<int> sets[2];
        queue<int> q;
        for(int j=0;j<n;j++){        //graph can be disconnected hence multiple parts 
            if(sets[0].count(j)||sets[1].count(j))continue;  //already colored
            q.push(j);
            sets[0].insert(j);
            while(!q.empty()){
                int s=q.size();
                while(s--){
                    int curr=q.front();
                    q.pop();
                    int curr_set=sets[0].count(curr)>0?0:1;
                    for(auto i:graph[curr]){
                        if(sets[0].count(i)==0&&sets[1].count(i)==0){
                            sets[1-curr_set].insert(i);
                            q.push(i);
                        }else if(sets[curr_set].count(i)>0){
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};