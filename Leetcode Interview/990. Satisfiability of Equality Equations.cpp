/*
We have 26 nodes in the graph.
All "==" equations actually represent the connection in the graph.
The connected nodes should be in the same color/union/set.

Then we check all inequations.
Two inequal nodes should be in the different color/union/set.

Explanation
We can solve this problem by DFS or Union Find.

Firt pass all "==" equations.
Union equal letters together
Now we know which letters must equal to the others.

Second pass all "!=" inequations,
Check if there are any contradict happens.

Time Complexity:
Union Find Operation, amortized O(1)
First pass all equations, O(N)
Second pass all inequations, O(N)

Overall O(N)

*/
class Solution {
public:
    int parent[26];
    
    int find(int src){
        if(src!=parent[src])parent[src]=find(parent[src]);
        return parent[src];
    }
    
    bool equationsPossible(vector<string>& eqs) {
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(auto e:eqs){
            if(e[1]=='='){
                parent[find(e[0]-'a')]=parent[find(e[3]-'a')];
            }
        }
        
        for(auto e:eqs){
            if(e[1]=='!'){
                if(find(e[0]-'a')==find(e[3]-'a'))return false;
            }
        }
        return true;
        
    }
};