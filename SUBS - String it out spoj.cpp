#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

bool isSubSequence(string &str1,string &str2, int m, int n) 
{ 
   int j = 0;
  
   for (int i=0; i<n&&j<m; i++) 
       if (str1[j] == str2[i]) 
         j++; 
         
   return (j==m); 
} 

string multi(string &s,int m){
    string ans="";
    if(m==0)return ans;
    
    for(int i=0;i<s.length();i++){
        char temp=s[i];
        for(int j=0;j<m;j++){
            ans+=temp;
        }
    }
    return ans;
}

int32_t main(){
    
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.length();
        int m=s2.length();
        int h=m/n+1;
        int l=0;
        int ans=0;
        //cout<<n<<" "<<m<<" "<<h<<endl;
        while(l<=h){
            int mid=(l+h)/2;
            //cout<<mid<<endl;
            string x=multi(s1,mid);
            string y=s2;
            //cout<<x<<" "<<y<<endl;
            if(isSubSequence(x,y,x.length(),m)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        
        cout<<ans<<endl;
        
    }
	return 0;
}

