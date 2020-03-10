/*
Let’s write a recurrence for the answer. Let T0(n) be the number of valid strings ending in 0, and T1(n) be the number of valid strings ending in 1. Since n >= 1, the answer is T0(n) + T1(n).

We can find some base cases.

T0(1) = 1, since there is one string of length one that ends with 0, i.e., 0
T0(2) = 1, since there is one string of length two that ends with 0, i.e., 10
Now consider T0(n) for n >= 3. Given a string of length n that ends in 0, there are two cases, of which exactly one applies. The first case is that the string ends in 10, in which case dropping the 0 gives a valid string of length n - 1 ending in 1. The second case is that the string ends in 000, in which case dropping the 00 gives a valid string of length n - 2 ending in 0.

T0(n) = T0(n - 2) + T1(n - 1)
We observe by the symmetry of problem that T0(n) = T1(n).

T0(n) = T0(n - 2) + T0(n - 1)
This is the Fibonacci recurrence. The answer is T0(n) + T1(n) = 2 Fib(n).

*/
//Tutorial dekhio iska sidha sidha formula hai bc

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n)	for(int i = 0; i < (n); ++i)
#define repA(i, a, n)	for(int i = a; i <= (n); ++i)
#define repD(i, a, n)	for(int i = a; i >= (n); --i)
#define trav(a, x)	for(auto& a : x)
#define fast	ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);
#define clr(a)	memset(a, 0, sizeof(a))
#define all(x)	(x).begin(), (x).end()
#define h(x)	((int)(x).size())
#define vi	vector<int>
#define vl	vector<ll>
#define vpii	vector<pair<int, int>>
#define vpll	vector<pair<ll, ll>>
#define ff	first
#define ss	second
#define mp	make_pair
#define pb	push_back

typedef long double ld;
typedef long long int ll;

ll a, b, c, d;
ll ans[2] = { 0,0 };
void fast_fib(ll n, ll MOD) {
	if (n == 0) {
		ans[0] = 0;
		ans[1] = 1;
		return;
	}
	fast_fib((n / 2), MOD);
	a = ans[0];	//F(n)
	b = ans[1];	//F(n+1)
	c = 2 * b - a;
	if (c < 0)
		c += MOD;
	c = (a * c) % MOD;	//F(2n)
	d = (a*a + b * b) % MOD;	//F(2n + 1)
	if (n % 2 == 0) {
		ans[0] = c;
		ans[1] = d;
	}
	else {
		ans[0] = d;
		ans[1] = c + d;
	}
}	// ans[0] is the nth fibonacci number

int main() {
	fast;
	int t;
	cin >> t;
	rep(i, t) {
		int n, m;
		cin >> n >> m;
		fast_fib(n, m);
		cout << 2 * ans[0] % m << '\n';
	}
}