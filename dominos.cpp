#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>*edges,unordered_set<int> &visited,stack<int> &stack,int start)
{
    visited.insert(start);
    for(int i=0;i<edges[start].size();i++)
    {
        int adj=edges[start][i];
        if(visited.count(adj)==0)
        {
            dfs(edges,visited,stack,adj);
        }
    }
    stack.push(start);
}

void dfs2(vector<int>*edges,unordered_set<int> &visited,int start)
{
    visited.insert(start);
    for(int i=0;i<edges[start].size();i++)
    {
        int adj=edges[start][i];
        if(visited.count(adj)==0)
        {
            dfs2(edges,visited,adj);
        }
    }                                          // MAKE VISITED BOOL ARR TIME COMP SET KI JYADA HAI
}

int getnumber(vector<int>*edges,vector<int>*edgest,int n)
{
    unordered_set<int> visited;
    stack<int> stack;
    for(int i=0;i<n;i++)
    {
        if(visited.count(i)==0)
        {
            dfs(edges,visited,stack,i);
        }
    }
    visited.clear();
    int count=0;
    while(stack.size()!=0)
    {
        int element=stack.top();
        stack.pop();
        if(visited.count(element)==0)
        {
            dfs2(edges,visited,element);
            count++;
        }
    }
    return count;
}

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>*edges= new vector<int>[n];
        vector<int>*edgest=new vector<int>[n];
        int m;
        cin>>m;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            edges[x-1].push_back(y-1);
            edgest[y-1].push_back(x-1);
        }
        int output=getnumber(edges,edgest,n);
        cout<<output<<endl;
        delete [] edges;
        delete [] edgest;
    }
	return 0;
}

