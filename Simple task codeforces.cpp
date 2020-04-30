/*In this problem we will be using counting sort. So for each query we will count the number of occurrences for each character, and then update the range like this

for(int j=x;j<=y;j++)
  cnt[s[j] - 'a']++;
ind = 0;
for(int j=x;j<=y;j++)
{
  while(cnt[ind] == 0)
    ind++;
  s[j] = ind + 'a';
  cnt[ind]--;
}
But this is too slow. We want a data structure that can support the above operations in appropriate time.

Let’s make 26 segment trees each one for each character. Now for each query let’s get the count of every character in the range, and then arrange them and update each segment tree with the new values. We will have to use lazy propagation technique for updating ranges.

Time complexity:  where sz is the size of the alphabet (i.e. = 26).   O(sz*lgn*Q);

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <utility>
#include <iomanip>
#include <set>
#include <numeric>
#include <cassert>
#include <ctime>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define PI acos(-1.0)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

int tree[400005][27], lazy[400005][27];
char s[100005];

void build(int i,int L,int R)        //har letter ka count rakhna
{
  if(L == R)
  {
    tree[i][s[L] - 'a'] = 1;
    for(int j=0;j<26;j++)
      lazy[i][j] = -1;
    return ;
  }
  build(i*2 + 1, L, (L + R) / 2);
  build(i*2 + 2, (L + R) / 2 + 1, R);
  for(int j=0;j<26;j++)
  {
    lazy[i][j] = -1;
    tree[i][j] = tree[i*2 + 1][j] + tree[i*2 + 2][j];
  }
}

void update(int i, int L, int R, int x, int y, int val, int j)//particular letter ko range me har jagah place karna
{
  if(lazy[i][j] != -1)
  {
    tree[i][j] = lazy[i][j] * (R - L + 1);          //us range me letter daal diye har jagah
    if(L != R)
    {
      lazy[i*2+1][j] = lazy[i][j];
      lazy[i*2+2][j] = lazy[i][j];
    }
    lazy[i][j] = -1;
  }
  if(L >= x && R <= y)
  {
    lazy[i][j] = val;
    tree[i][j] = lazy[i][j] * (R - L + 1);
    if(L != R)
    {
      lazy[i*2+1][j] = lazy[i][j];
      lazy[i*2+2][j] = lazy[i][j];
    }
    lazy[i][j] = -1;
    return;
  }
  if(L > y || R < x)
    return;
  update(i*2 + 1, L, (L + R) / 2, x, y, val, j);
  update(i*2 + 2, (L + R) / 2 + 1, R, x, y, val, j);
  tree[i][j] = tree[i*2 + 1][j] + tree[i*2 + 2][j];
}

int query(int i, int L, int R, int x, int y, int j)    //returns number of particular letter in range
{
  if(lazy[i][j] != -1)
  {
    tree[i][j] = lazy[i][j] * (R - L + 1);
    if(L != R)
    {
      lazy[i*2+1][j] = lazy[i][j];
      lazy[i*2+2][j] = lazy[i][j];
    }
    lazy[i][j] = -1;
  }
  if(L >= x && R <= y)
    return tree[i][j];
  if(L > y || R < x)
    return 0;
  return query(i*2 + 1, L, (L + R) / 2, x, y, j) + query(i*2 + 2, (L + R) / 2 + 1, R, x, y, j);
}

void get(int i, int L, int R, int j)
{
  if(lazy[i][j] != -1)
  {
    tree[i][j] = lazy[i][j] * (R - L + 1);
    if(L != R)
    {
      lazy[i*2+1][j] = lazy[i][j];
      lazy[i*2+2][j] = lazy[i][j];
    }
    lazy[i][j] = -1;
  }
  if(!tree[i][j])
    return ;
  if(L == R)
  {
    s[L] = j + 'a';
    return;
  }
  get(i*2 + 1, L, (L + R) / 2, j);
  get(i*2 + 2, (L + R) / 2 + 1, R, j);
}

int cnt[26];

int main()
{
  //ios_base::sync_with_stdio(0);
  //freopen("test0.txt", "r", stdin);
  //freopen("lca.out", "w", stdout);
  int n, q, x, y, up;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  build(0, 0, n - 1);
  for(int i=0;i<q;i++)
  {
    scanf("%d %d %d", &x, &y, &up);
    x--, y--;
    for(int j=0;j<26;j++)
      cnt[j] = query(0, 0, n - 1, x, y, j);         //number of every letter in range
    int curr = x;
    if(!up) curr = y;
    for(int j=0;j<26;j++)                 //a b c d ----- z tak loop
    {
      if(!cnt[j]) continue;
      update(0, 0, n - 1, x, y, 0, j);
      if(up)
      {
        update(0, 0, n - 1, curr, curr + cnt[j] - 1, 1, j);    //in asceding order of letter place karte jao
        curr+=cnt[j];
      }
      else
      {
        update(0, 0, n - 1, curr - cnt[j] + 1, curr, 1, j);    //piche se place karte jao
        curr-=cnt[j];
      }
    }
  }
  for(int i=0;i<26;i++)
    get(0, 0, n - 1, i);       //har letter ko ans me place karte jao
  printf("%s", s);
  return 0;
}