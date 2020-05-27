class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(N+1);
        
        int n = dislikes.size();
        
        for (int i = 0; i < n; i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>color(N+1, -1);
        
        for (int i = 1; i <= N; i++) {
            if (color[i] != -1)
                continue;
            
            queue<int>q;
            q.push(i);
            color[i] = 1;
            
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (int j = 0; j < graph[t].size(); j++) {
                    if (color[graph[t][j]] == -1) {
                        color[graph[t][j]] = 1-color[t];
                        q.push(graph[t][j]);
                    } else if (color[graph[t][j]] == color[t]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};