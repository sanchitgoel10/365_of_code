/*
Doubling//Binary Lifting
Since There will be at most 5*10^4 queries for method getKthAncestor,
Let's set queries called time as N,
It means, the brute force's complexity will become O(NK)......-> TLE!

So we have to reduce eighter N or K.
here, N is the number of queries, the element we cannot influence, so we know we have to reduce the time complexity for getKthAncestor.

When you want to get [K]th ancestor of [node], if you have already known [K/2]th ancestor, as what we talk in the first part, we can use [K/2]th parent twice to get the answer. If you notice this, then everything becomes simple.

But what if we remember the whole kth (1st, 2nd, 3th, 4th.....) ansestor?
in that case, we only use O(1) for getKthAncestor, but to prepare the data, we need to take O(K^2) -> TLE!!!.

So we need a much more efficient way to prepare & get data...
Let's see the parent again:

we have 1st parent for node.
use this, we can know 2nd parent, by searching [1st parent]'s [1st parent],
to know the 3rd parent, trace [2nd parent]'s [1st parent]
to know the 4th parent, trace [2nd parent]'s [2nd parent] -> we memory it as [4th parent]
to know the 5th parent, trace [4th parent]'s [1st parent]
.....
conclution
Here, we can make a P[i][node], it means [node]'s [2^i]th parent.
and when we want to take the Kth parent, we just turn the number 'k' to binary number, and see the bits to trace parent.

for example

let's set K = 5, 
5 (in 10 base ) = 101(in 2 base), 
so we find the (2^0) parent firstly, then find the (2^2) parent,
*/
class TreeAncestor {
    vector<vector<int>>v;
public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> par(n,vector<int>(20));
        for(int i=0;i<n;i++) par[i][0] = parent[i];
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){        //i=node
                if(par[i][j-1] == -1) par[i][j] = -1;
                else par[i][j] = par[par[i][j-1]][j-1];        //4=2*2,8=4*2,16=8*2 wahi hai bas 
            }
        }
        swap(v,par);      
    }
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){              //loop can be run in either direction be it 0-20 or 20-0 because eg 5 can be 4th ka 1st parent ya 1st ka 4th parent
            if(k & (1 << i)){
                node = v[node][i];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};


//Another way for the bit part
int getKthAncestor(int node, int k) {
        for(int i = 19; i >= 0; i--){ // remember to check the bit from TOP!!!!!!!! Kyuki sabse bada subtract karega to chota hi possible hai but chota kardega to pata nhi bada hoga ki nhi
		    int num = pow(2, i); // we don't think bit, just see if we can jump to [num th] ancestor
            if(k >= num){        // if we can
                node = P[i][node];
				k -= num;         // we jump back, so the rest step is [k - num]
                if(node == -1) return -1;				
            }
        }

        return node;
    }