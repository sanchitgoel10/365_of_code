Wrong Completely wrong

//Normal topological doesnt work as it dont take care of the depth,basically choose the course which would open path for many other courses.
int dfs(vector<vector<int>>& al, vector<int> &depth, int i) {
    if (depth[i] == -1) {
        depth[i] = 0;
        for (int j : al[i])
            depth[i] = max(depth[i], 1 + dfs(al, depth, j));        //getting depth 
    }
    return depth[i];
}
int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
    int res = 0;
    vector<vector<int>> al(n + 1);
    vector<int> depth(n + 1, -1), pre(n + 1), q;
    for (auto &d : dependencies) {
        al[d[0]].push_back(d[1]);
        ++pre[d[1]];
    }
    for (int i = 1; i <= n; ++i)
        dfs(al, depth, i);
    for (auto i = 1; i <= n; ++i)
        if (pre[i] == 0)
            q.push_back(i);                
    while (!q.empty()) {
        ++res;
        sort(begin(q), end(q),[&](int n1, int n2){ return depth[n1] > depth[n2]; });    //max to low sort kara hai depth me
        int take = min((int)q.size(), k);
        for (auto i = 0; i < take; ++i) {
            for (auto j : al[q[i]])
                if (--pre[j] == 0)
                    q.push_back(j);
        }
        q.erase(begin(q), begin(q) + take);      //queue nhi vector use kara hai to khud erase karna pad raha hai
    }
    return res;
}
/*A topological sort is the first to come to mind for a dependency graph, but it did not seem as a good fit for this problem to me.

Instead, we can use dfs to find out the depth of each course. At the same time, we can count the number of prerequisites pre for each course.

We put all courses that we can take (pre[i] == 0) to a queue. We then sort courses in our queue by the depth, and take up to k "deepest" courses. When we take each course, we decrement pre[j] of each dependent course. If all prerequisites are met for a dependent course, we add it to the queue, so it's considered for the next semester.

Here, I am using a vector as my queue. I also tried to use a set or priority queue instead, but it looked messy as you need to add new courses after processing the semester. So, I think that vector + sort is a better fit for this problem.*/