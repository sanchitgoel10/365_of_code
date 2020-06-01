/*
If we have say "A....B", where A = B, then we should write "AAAAAA".

If we have "R....L", then we will write "RRRLLL", or "RRR.LLL" if we have an odd number of dots. If the initial symbols are at positions i and j, we can check our distance k-i and j-k to decide at position k whether to write 'L', 'R', or '.'.

(If we have "L....R" we don't do anything. We can skip this case.)
'R......R' => 'RRRRRRRR'
'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
'L......R' => 'L......R'
'L......L' => 'LLLLLLLL'
*/
string pushDominoes(string d) {
        d = 'L' + d + 'R';                //This takes care of the border values
        string res = "";
        for (int i = 0, j = 1; j < d.length(); ++j) {         
            if (d[j] == '.') continue;
            int middle = j - i - 1;
            if (i > 0) res += d[i];
            if (d[i] == d[j]) res += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R') res += string(middle, '.');
            else res += string(middle / 2, 'R') + string(middle % 2,'.') + string(middle / 2, 'L');    //middle%2 takes care of odd even length
            i = j;
        }
        return res;
    }
//Same with l and r
string pushDominoes(string dominoes) {
        string d = 'L' + dominoes + 'R';
        string res;
        int l = 0, r = 1, m = d.size();
        while (r < m) {
            if (d[r] == '.') {
                r++;
                continue;
            }
            if (l > 0) 
                res += d[l];
            int mid = r - l - 1;
            if (d[r] == d[l]) {
                res += string(mid, d[l]);
            } else if (d[r] == 'R') {
                res += string(mid, '.');
            } else {
                res += string(mid/2, 'R') + string(mid%2, '.') + string(mid/2, 'L');
            }
            l = r;
            r++;
        }
        return res;
    }