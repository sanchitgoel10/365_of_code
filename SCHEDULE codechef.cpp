/*input
2
9 1
1100001111
4 0
1110001011011
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
bool check(string s,int changes, int mid){
    ll count = 1;
    string s1 = s;
    ll ans = 0;
    bool flag = true;
    for(int i=1;i<s1.length();i++){
        
        if(s1[i]==s1[i-1]){
            count++;
        }
        else{
            ans += count/(mid+1);
            count = 1;
        }
    }
    ans += count/(mid+1);
    if(ans<=changes) return true;
    return false;
}



ll binary(string s, ll k){
    ll l = 2,r= s.length();
    ll ans = r;
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(s,k,mid)){
            r = mid-1;
            ans = mid;
        }
        else
            l = mid+1;
    }
    return ans;
}

bool check1(string s, ll k){
    ll count01 = 0,count10 = 0;
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            if(s[i]=='0') count10++;
            else count01++;
        }
        else{
            if(s[i]=='0') count01++;
            else count10++;
        }
    }
    if(min(count10,count01)<=k) return true;
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        string s; cin >> s;
        if(check1(s,k))
            cout << 1 << "\n";
        else
            cout << binary(s,k) << "\n";
    }
    return 0;
}