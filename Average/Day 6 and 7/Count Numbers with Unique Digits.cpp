

class Solution {
public:
    int arr[11]={9,9,8,7,6,5,4,3,2,1,0};
    int countNumbersWithUniqueDigits(int n){
        if(n==0)return 1;
        int*dp=new int[n+1];
        dp[1]=10;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1];
            int temp=1;
            for(int j=0;j<min(11,i);j++){
                temp*=arr[j];
            }
            dp[i]+=temp;
        }
        return dp[n];
    }
};