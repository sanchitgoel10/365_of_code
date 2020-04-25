#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
class node{
    public:
    int mx;
    int count;
};
/*
 * Complete the 'getMaxCharCount' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. 2D_INTEGER_ARRAY queries
 */

node query(node*tree,int s,int e,int l,int r,int tn){
    if(l>e||r<s){
        node ans;
        ans.mx=0;
        ans.count=0;
        return ans;
    }
    if(s>=l&&e<=r){
        return tree[tn];
    }
    int mid=(s+e)/2;
    node ans1=query(tree,s,mid,l,r,2*tn);
    node ans2=query(tree,mid+1,e,l,r,2*tn+1);
    
    node ans;
    if(ans1.mx==ans2.mx){
        ans.mx=ans1.mx;
        ans.count=ans1.count+ans2.count;
    }else if(ans1.mx>ans2.mx){
        ans.mx=ans1.mx;
        ans.count=ans1.count;
    }else{
        ans.mx=ans2.mx;
        ans.count=ans2.count;
    }
    return ans;
}


void build(node*tree,string S,int n){
    
    for(int i=0;i<n;i++){
        if(int(S[i])>90){
            tree[n+i].mx=int(S[s])-96;
            tree[n+i].count=1;
        }else{
            tree[n+i].mx=int(S[s])-64;
            tree[n+i].count=1;
        }
    }

    for(int i=n-1;i>0;i--){
        
    }
    
    
    tree[tn].mx=max(tree[2*tn].mx,tree[2*tn+1].mx);
    
    if(tree[2*tn].mx==tree[2*tn+1].mx){
        tree[tn].count=tree[2*tn].count+tree[2*tn+1].count;
    }else{
        if(tree[2*tn].mx>tree[2*tn+1].mx){
            tree[tn].count=tree[2*tn].count;
        }else{
            tree[tn].count=tree[2*tn+1].count;
        }
    }
}

vector<int> getMaxCharCount(string s, vector<vector<int>> queries) {
    // queries is a n x 2 array where queries[i][0] and queries[i][1] represents x[i] and y[i] for the ith query.
    int n=s.length();
    node*tree = new node[4*n];
    build(tree,s,0,n-1,1);
    vector<int> ans;
    int l=queries.size();
    for(int i=0;i<l;i++){
        ans.push_back(query(tree,0,n-1,queries[i][0],queries[i][1],1).count);
    }
    return ans;
}

int main()
{
    FastRead;
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);
    n = s.size();
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> query(q);

    for (int i = 0; i < q; i++) {
        query[i].resize(2);

        string query_row_temp_temp;
        getline(cin, query_row_temp_temp);

        vector<string> query_row_temp = split(rtrim(query_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int query_row_item = stoi(query_row_temp[j]);

            query[i][j] = query_row_item;
        }
    }

    vector<int> ans = getMaxCharCount(s, query);

    for (int i = 0; i < (int)ans.size(); i++) {
        fout << ans[i];

        if (i != (int)ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
