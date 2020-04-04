#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long int

bool cmp(vector<int> v1,vector<int> v2){
    return v1[0]<v2[0];               //sorting according to dist
}

int solve(vector<vector<int>> checkpts){
    int n=checkpts.size();
    
    vector<int> dp(n+1);
    dp[n]=1;
    sort(checkpts.begin(),checkpts.end(),cmp);
    
    for(int i=n-1;i>=0;i--){
        if(checkpts[i][2]==-1){
            dp[i]=dp[i+1]+checkpts[i][1];     // Eating dish 
        }else{
            if(checkpts[i][1]>dp[i+1]){
                dp[i]=dp[i+1];                             //required to take help from clan is more than required in next step
            }else{
                dp[i]=max(max(dp[i+1]-checkpts[i][2],(int)1),checkpts[i][1]);
                //first max inside max is between after taking help required,1
                //overall max is men req to take help,andar ka max;
            }
        }
    }
    
    return dp[0];
}

int32_t main() {
    FastRead;
	int t;
	cin>>t;
	while(t--){
	    int i, j, num_tests, dest, num_dishes, num_chiefs, dist;
	    int num1, num2;
	    cin>>dest;
	    cin>>num_dishes;
	    vector<vector<int> > checkpts;
	    for(int i=0;i<num_dishes;i++){
	        cin>>dist>>num1;
	        checkpts.push_back({dist,num1,-1});    //-1 means dish
	    }
	    cin>>num_chiefs;
	    for(int i=0;i<num_chiefs;i++){
	        cin>>dist>>num1>>num2;
	        checkpts.push_back({dist,num1,num2});
	    }
	    
	    cout<<solve(checkpts)<<endl;
	    
	}
	return 0;
}
