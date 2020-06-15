int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles) total += (p + m - 1) / m;      //(p+m-1)/m==ceil(p/double(m))  //double to truncate properly
            if (total > H) l = m + 1; else r = m;
        }
        return l;
    }