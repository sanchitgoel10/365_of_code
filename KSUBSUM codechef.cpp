#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t, n, k[3], i, j, cum, bs;
	cin >> t;
	while(t--) {
		cin >> n >> k[0] >> k[1] >> k[2];
		ll a[n];
		multiset<ll> b, c;
		for(i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(bs = i = 0; i < n; i++) {
			for(cum = 0, j = i; j < n; j++) {
				cum += a[j];
				if(b.size()< k[2]) {
					b.insert(cum);
					++bs;
				}
				else if(*b.begin() < cum) {
					b.erase(b.begin());
					b.insert(cum);
				}
			}
		}
		cum = k[2];
		multiset<ll> :: reverse_iterator rit;
		multiset<ll> :: iterator it;
		bs = 0;
		for(it = b.begin(); it != b.end(); it++) {
			if(cum == k[2] || cum == k[1] || cum == k[0]) {
				c.insert(*it);
				if(c.size()==3)break;
			}
			cum--;
		}
		for(rit = c.rbegin(); rit != c.rend(); rit++) {
			cout << *rit << ' ';
		}
		cout << '\n';
	}
	return 0;
}