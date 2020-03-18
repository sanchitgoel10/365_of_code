#include <bits/stdc++.h>
using namespace std;
#define next(x) ((x == n-1) ? 0 : x+1)
#define prev(x) ((x == 0) ? n-1 : x-1)

int k;
string str;

bool solve() {
    int n = str.size();
    if (n == 1) {
        if (str[0] == '?')
            str[0] = '0';
        return true;
    }
    for (int i = 0; i < n; i++)
        if (str[i] != '?' && str[i] == str[next(i)])
            return false;
    if (k == 1)
        return false;
    if (k == 2) {
        if (n & 1)
            return false;
        for (int i = 0; i < 2; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++)
                if (str[j] != '?' && str[j] != '0' + (i+j) % 2) {
                    flag = false;
                    break;
                }
            if (!flag)
                continue;
            for (int j = 0; j < n; j++)
                str[j] = '0' + (i+j) % 2;
            return true;
        }
        return false;
    }
    for (int i = 0; i < n; i++) {
        char c1 = str[i], c0 = str[prev(i)], c2 = str[next(i)];
        if (c1 == '?') {
            if (c0 != '0' && c2 != '0')
                str[i] = '0';
            else if (c0 != '1' && c2 != '1')
                str[i] = '1';
            else
                str[i] = '2';
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> k >> str;
        (solve()) ? cout << str << endl : cout << "NO\n";
    }
}