#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl "\n"

typedef struct data{
    data* child[26];
    int cnt=0;
}trie;

trie* root;
int ans=0;

void insert(string &s){
    
    trie *curr=root;
    for(int i=0;i<s.size();i++){
        
        char ch=s[i];
        int reqd=ch-'A';
        if(!curr->child[reqd])
            curr->child[reqd]=new trie();
        curr=curr->child[reqd];
    }
    curr->cnt++;
}

void dfs(trie *curr,int lvl,int k){
    
    for(int i=0;i<=25;i++){
        if(curr->child[i]){
            dfs(curr->child[i],lvl+1,k);
            curr->cnt+=curr->child[i]->cnt;
        }
    }
    while(curr->cnt>=k){
        curr->cnt-=k;
        ans+=lvl;
    }
}

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<string> v(n);
        root = new trie();
        ans=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            insert(v[i]);
        }
        dfs(root,0,k);
        cout<<"Case"<<" "<<"#"<<tc<<":"<<" "<<ans<<endl;
        tc++;
    }
}