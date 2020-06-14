class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int inf=1e9;
        K++;
        vector<vector<int>> ans(n,vector<int>(K+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<=K;j++){
                ans[i][j]=inf;
            }
        }
        ans[src][0]=0;
        for(int i=1;i<=K;i++){
            for(int j=0;j<n;j++){
                ans[j][i]=ans[j][i-1];      //one less stop that is been already calculated
            }
            for(auto &v:flights){
                ans[v[1]][i]=min(ans[v[1]][i],ans[v[0]][i-1]+v[2]);        //increasing one stop at every possible path
            }
        }
        if(ans[dst][K]==inf)return -1;
        return ans[dst][K];
    }
};

//Pq solution 
/*
put all flights into a prices map -> Map<Integer, Map<Integer, Integer>>
// source city : Map<destination city, price>
init a min pq -> each object in pq should be an int array with
top[0] = current total price
top[1] = current source city
top[2] = max distance to destination allowed
pq compares each object by total price so far
add original source city to pq with price = 0 & distance allowed = k + 1
while exists cities to explore
--> get min object then remove it from pq
--> get current total price, current source city & distance to destination allowed from min object
--> if current source == destination (obviously distance from original source to current source [which is destination] is less than k) -> return current total price
else find (from prices map) all connected flights that fly from current source + calculate new price, new current source & new distance + add them to pq
If no city left to explore and no flight that fits criteria found till now, return -1


*/
typedef tuple<int,int,int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>vp(n);
        for(const auto&f:flights)   vp[f[0]].emplace_back(f[1],f[2]);
        priority_queue<ti,vector<ti>,greater<ti>>pq;
        pq.emplace(0,src,K+1);
        while(!pq.empty()){
            auto [cost,u,stops] = pq.top();
            pq.pop();
            if(u==dst)  return cost;
            if(!stops)  continue;
            for(auto to:vp[u]){
                auto [v,w] = to;
                pq.emplace(cost+w,v,stops-1);
            }
        }
        return -1;
    }
};