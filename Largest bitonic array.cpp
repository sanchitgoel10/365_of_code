 	
int longestBitonicSubarray(int *input, int n) {
		
	int *left=new int[n];
    int *right= new int[n];
    left[0]=1;
    for(int i=1;i<n;i++)
    {
        left[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[j]>=input[i])
                continue;
            int poss=left[j]+1;
            if(poss>left[i])
                left[i]=poss;
        }
    }
    right[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        right[i]=1;
        for(int j=i+1;j<n;j++)
        {
            if(input[j]>=input[i])
                continue;
            int poss=right[j]+1;
            if(poss>right[i])
                right[i]=poss;
        }
    }
    int *output=new int[n];
    for(int i=0;i<n;i++)
    {
        output[i]=left[i]+right[i]-1;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(output[i]>ans)
            ans=output[i];
    }
    delete [] output;
    delete [] left;
    delete [] right;
    return ans;	
     	
}

