class Solution {
public:
    
    int check(vector<int>& p, int m, int force) {
        int pos = p[0];
        m--;
        for (auto i = 1; i < p.size(); ++i)
            if (p[i] - pos >= force) {
                --m;
                pos = p[i];
                if(m==0)return 1;
            }
        return 0;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(begin(p), end(p));
        int l = 1, r = 999999999;
        while (l < r) {
            int mid = (r + l) / 2 + 1;
            if (check(p, m, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};