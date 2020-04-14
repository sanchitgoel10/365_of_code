#include<bits/stdc++.h>
using namespace std;

void BFS(int**edges,int n,int sv,bool*visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(edges[curr][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    } 
}

int connected(int**edges,int n){
    bool* visited = new bool[n]();
    int count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            BFS(edges,n,i,visited);
            count++;
        }
    }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        edges[u[i]-1][v[i]-1]=1;
        edges[v[i]-1][u[i]-1]=1;
    }
    
    int ans=connected(edges,n);
    
    for(int i=0;i<n;i++){
        delete edges[i];
    }
    delete [] edges;
    
    return ans;
}