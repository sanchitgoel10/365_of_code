class Solution {
public:
    int getparent(int src,vector<int>&parent){       //get parent
        if(parent[src]==src)
            return src;
        return parent[src]=getparent(parent[src],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int count=0;
        int n=edges.size();
        vector<int> parent(n+1,0);
        for(int i=1;i<=n;i++){//union find jaisa
            parent[i]=i;
        }
        int i=0;
        while(count<n-1){                    //idea is form mst //kruskals     /
            auto e=edges[i];
            int sp=getparent(e[0],parent);
            int dp=getparent(e[1],parent);
            if(sp!=dp){                    //needed in mst
                count++; 
                parent[sp]=parent[dp];
            }else{                      //not needed and we know there is only 1 such edge therfore return
                return e; 
            }
            i++;
        }
        return edges[n-1];        //last edge is remaining
    }
};