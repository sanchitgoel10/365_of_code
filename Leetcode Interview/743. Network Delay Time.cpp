//DijKstra's Algorithm
typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> g[n + 1];
        for (const auto& t : times) {
            g[t[0]].push_back(make_pair(t[1], t[2]));
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(make_pair(0, k));
        int u, v, w;
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace_back(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};
//Bellman Ford
/*The solution actually use some thought of dynamical programming
Subproblem: dp(i) represents minimum distance from K to i (iteratively update dp(i) when we find another shorter distance from K to i)
Base case 1:
initialize MAX value as initial minimum distance from K to every point
initialize 0 as min distance to K itself
Recurrence relation: traverse all destinations, if dp[u] (starting point of current edge) has already been visited, and new distance from u to v is smaller than previous saved distance, we should update minimum distance from u to v
After getting minimum distance (travel time) to all points, we should retrieve the max distance from these minimum distance, to ensure that we can travel all points in a specific travel time
If we do not visit all points, we should return -1
Complexity is O(VE), but the problem said N will be no more than 100, so the complexity should be O(E)
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};