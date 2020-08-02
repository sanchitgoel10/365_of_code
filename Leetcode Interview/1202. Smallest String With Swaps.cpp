class Solution {
private:
    /*
     * Find the subset a vertex belongs to.
     */
    int find(vector<int> &parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
    

public:
    
    /* We use disjoint set (or Union-Find) to form subsets */
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        /* 
         * Treat index of string s as vertex. Create parent subsets 
         * and initialize them to -1 - this means the subsets don't
         * have parent info yet.
         */
        vector<int> parent;
        for (int i = 0; i < s.size(); i++) parent.push_back(i);
        
        /*
         * Go through each pair one by one. Find the subsets
         * that the vertices of the pair belong to. If they 
         * are different, unionize them.
         */
        for (int i = 0; i < pairs.size(); ++i) {
            int x = find(parent, pairs[i][0]), y = find(parent, pairs[i][1]);            
            if (x != y){
                parent[x]=parent[y];
            }
        }
        
        /* Create separate vectors from the subsets */
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < s.size(); i++) m[find(parent,i)].push_back(i);
        
        /* Sort the vertices in each vector and change the original 
         * array based on the sorted results 
         */
        for (auto x : m) {
            string str = ""; int j = 0;
            for (auto i : x.second) { str += s[i]; }
            sort(str.begin(), str.end());
            for (auto i : x.second) { s[i] = str[j++]; }
        }
        
        return s;
    }
};