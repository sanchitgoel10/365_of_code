class Solution {
public:
    int power(int num){
        if(num<2)return 0;
        return 1+(num%2?power(num*3+1):power(num/2));
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++){
            v.push_back({power(i),i});
        }
        nth_element(v.begin(),v.begin()+k-1,v.end());    //this is partial sort time comp O(n) rather than full sorting
        return v[k-1].second;
    }
    
};
/*
Faster precompute all of them
We can use a static array to precompute powers for numbers [1..1000]. To speed-up pre-computation, I initially used memosiation, but it did not make a difference in OJ (perhaps, it might if the range is wider).

Also, we do not need to sort the entre subrange; we can use a partial sort (like nth_element in C++).

Note: I need to put the static array outside of the solution class; you'll need to define it if you want to put it inside.
Another note: I provide only the first 3 elements of comp to cut the initialization time. We'll populate the rest in the compute function. The comp[2] will be set to 1 afterwards, so we'll know that comp is ready to use.
*/
int comp[1001] = { 0, 0, 0 };
class Solution {
    int compute(int i) {
    return i < 2 ? 0 :
        1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
    }
public:
    int getKth(int lo, int hi, int k) {
        if (comp[2] == 0)
            for (auto i = 2; i <= 1000; ++i)
                comp[i] = compute(i);
        vector<int> sorted(hi - lo + 1);
        iota(begin(sorted), end(sorted), lo);
        nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j) {
            return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
        return sorted[k - 1];
    }
};