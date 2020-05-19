/*The idea is:
0. To work on the same task again, CPU has to wait for time n, therefore we can think of as if there is a cycle, of time n+1, regardless whether you schedule some other task in the cycle or not.

To avoid leave the CPU with limited choice of tasks and having to sit there cooling down frequently at the end, it is critical the keep the diversity of the task pool for as long as possible.
In order to do that, we should try to schedule the CPU to always try round robin between the most popular tasks at any time.
priority_queue<task, count>
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<pair<int, char>> pq;
        for (pair<char, int> count : counts) {
            pq.push(make_pair(count.second, count.first));
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<pair<int, char>> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto t : tmp) {
                if (--t.first) {
                    pq.push(t);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};
//priority_queue<count>
//As @milu point out, we don't really need to store <task - count> pair in the priority_queue, we don't need to know the task name, store counts //works good enough:

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for (pair<char, int> count : counts) {
            pq.push(count.second);
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};