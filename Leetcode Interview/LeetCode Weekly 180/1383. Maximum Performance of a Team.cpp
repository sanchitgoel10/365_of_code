/*For a given efficiency, we pick all workers with the same or better efficiency. If the number of workers is greater than k, we pick k fastest workers.

Algorigthm
Sort workers based on their efficiency. Starting from the most efficient worker, compute and track the maximum performance. We can use a running sum to track all workers' speed.

When the amount of available workers exceeds k, remove the 'slowest' worker from sum. To do that, we can use a min heap.
*/
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> eff_sp;
    priority_queue <int, vector<int>, greater<int> > pq_speeds;
    long sum = 0, res = 0;
    for (auto i = 0; i < n; ++i)
        eff_sp.push_back({efficiency[i], speed[i]});
    sort(begin(eff_sp), end(eff_sp));
    for (auto i = n - 1; i >= 0; --i) {
        sum += eff_sp[i].second;
        pq_speeds.push(eff_sp[i].second);
        if (pq_speeds.size() > k) {
            sum -= pq_speeds.top();
            pq_speeds.pop();
        }
        res = max(res, sum * eff_sp[i].first);
    }
    return res % 1000000007;
}