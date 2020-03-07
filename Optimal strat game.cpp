int dp[101][101];
int find(int arr[],int st,int end){
    if(st==end){
        return arr[st];
    }
    if(st==end-1){
        return max(arr[st],arr[end]);
    }
    if(dp[st][end]!=-1){
        return dp[st][end];
    }
    dp[st][end]=max(arr[st]+min(find(arr,st+2,end),find(arr,st+1,end-1)),arr[end]+min(find(arr,st+1,end-1),find(arr,st,end-2)));
    return dp[st][end];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int st=0,end=n-1;
	    find(arr,st,end);
	    cout<<dp[0][end]<<endl;
	}
	return 0;
}
