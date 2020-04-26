#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long

int tree[400000][3];
int lazy[400000] = {0};
int zero, one, two;
int mid(int x,int y){
    return (x+y)/2;
}

void construct(int start, int end, int node)
{
    if(start == end){
        tree[node][2] = 1;
        return;
    }
    
    construct(start, mid(start, end), 2 * node + 1);
    construct(mid(start, end) + 1, end, 2 * node + 2);
    
    tree[node][2] = tree[2 * node + 1][2] + tree[2 * node + 2][2];
}

void update(int start, int end, int l, int r, int node)
{
    if(lazy[node]){
        zero = tree[node][0];
        one = tree[node][1];
        two = tree[node][2];
        tree[node][(lazy[node] % 3) % 3] = zero;
        tree[node][(lazy[node] % 3 + 1) % 3] = one;
        tree[node][(lazy[node] % 3 + 2) % 3] = two;
        
        if(start != end){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        
        lazy[node] = 0;
    }
    
    if(l > end || r < start)
        return;
    else if(l <= start && r >= end)
    {
        zero = tree[node][0];
        one = tree[node][1];
        two = tree[node][2];
        tree[node][1] = zero;
        tree[node][2] = one;
        tree[node][0] = two;
        
        if(start != end){
            lazy[2 * node + 1] += 1;
            lazy[2 * node + 2] += 1;
        }
        
        return;
    }
    
    update(start, mid(start, end), l, r, 2 * node + 1);
    update(mid(start, end) + 1, end, l, r, 2 * node + 2);
    
    tree[node][0] = tree[2 * node + 1][0] + tree[2 * node + 2][0];
    tree[node][1] = tree[2 * node + 1][1] + tree[2 * node + 2][1];
    tree[node][2] = tree[2 * node + 1][2] + tree[2 * node + 2][2];
}

int query(int start, int end, int l, int r, int node)
{
    if(lazy[node]){
        zero = tree[node][0];
        one = tree[node][1];
        two = tree[node][2];
        tree[node][(lazy[node] % 3) % 3] = zero;
        tree[node][(lazy[node] % 3 + 1) % 3] = one;
        tree[node][(lazy[node] % 3 + 2) % 3] = two;     
        
        if(start != end){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        
        lazy[node] = 0;
    }
    
    if((r < start) || (l > end))
        return 0;
    else if(l <= start && r >= end)
        return tree[node][2];
    else
        return query(start, mid(start, end), l, r, 2 * node + 1) + query(mid(start, end) + 1, end, l, r, 2 * node + 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
        
    for(lli i = 0; i < 4*n; i++)
    {
        tree[i][0] = 0;
        tree[i][1] = 0;
    }
    
    construct(0, n - 1, 0);
    
    for(lli i = 0; i < q; i++)
    {
        int type, l, r;
        
        cin >> type >> l >> r;
        
        if(type == 0){
            update(0, n - 1, l, r, 0);
        }
        else{
            cout << query(0, n - 1, l, r, 0) << "\n";
        }
    }
    
    return 0;
}
