{
	int t;
	cin>>t;
	while(t--){
	    int n,k,m;
	    cin>>n>>k>>m;
	    int a[n];
	    int b[n];
	    int c[k];
	    int d[m];
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<n;i++) cin>>b[i];
	    for(int i=0;i<k;i++) cin>>c[i];
	    for(int i=0;i<m;i++) cin>>d[i];
	    for(int i=0;i<n;i++) a[i]=a[i]-b[i];
	    sort(a,a+n,greater<int>());
	    multiset <int, greater <int> > s;   //reverse sorted multiset
	    for(int i=0;i<k;i++) s.insert(c[i]);
	    for(int i=0;i<m;i++) s.insert(d[i]);
	    multiset <int, greater <int> > :: iterator itr;     
	    itr=s.begin();
	    for(int i=0;i<n;i++){
	        if(itr==s.end()){
	                break;
	        }
	        int v=*itr;
	        if(a[i]>=v){
	            a[i]-=v;
	            itr++;
	        }else{
	            while(a[i]<v&&itr!=s.end()){   // to find the best possible number to subtract
	                itr++;
	                v=*itr;
	            }
	            if(itr==s.end()){
	                break;
	            }
	            if(a[i]>=v){
	                a[i]-=v;
	                itr++;
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++) ans+=a[i];
	    cout<<ans<<endl;
	    
	}
	return 0;
}