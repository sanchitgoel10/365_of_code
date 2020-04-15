#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll fact[1000000];
ll board[1003][1003];
ll visited[1003][1003];
int dir [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

void initialize()
{
    for(int i=0;i<1003;i++)
    {
        for( int j=0;j<1003;j++)
        {
            board[i][j]=1;
            visited[i][j]=0;
        }
    }
}

ll solve(int i,int j,int n,int m)
{
    visited[i][j]=1;
    ll count =1;
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        ll x=q.front().first;
        ll y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            ll newx=x+dir[i][0];
            ll newy=y+dir[i][1];
            if(newx<=0||newx>n||newy<=0||newy>m)
                continue;
            
            if(board[newx][newy]==3&&!visited[newx][newy])
            {
                count++;
                q.push(make_pair(newx,newy));
                visited[newx][newy]=1;
            }
            
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    fact[0]=1;
    for(ll i=1;i<100000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    
    while(t--)
    {
        initialize();
        int n,m,q;
        cin>>n>>m>>q;
        
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            board[x][y]=3;
        }
        
        ll temp;
        ll ans=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==3&&!visited[i][j])
                {
                    temp=solve(i,j,n,m);
                    ans=(ans*fact[temp])%mod;
                }
            }
        }
        cout<<ans%mod<<endl;
        
    }
	
	return 0;
}
