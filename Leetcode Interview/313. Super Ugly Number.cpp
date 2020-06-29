//See 264

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)return 1;
        vector<int> k(n);
        vector<int> p(primes.size(),0);
        k[0]=1;
        for(int i=1;i<n;i++){
            k[i]=k[p[0]]*primes[0];
            for(int j=1;j<primes.size();j++){
                k[i]=min(k[i],k[p[j]]*primes[j]);
            }
            for(int j=0;j<primes.size();j++){
                if(k[i]==k[p[j]]*primes[j]){
                    p[j]++;
                }
            }
        }
        return k[n-1];
    }
};