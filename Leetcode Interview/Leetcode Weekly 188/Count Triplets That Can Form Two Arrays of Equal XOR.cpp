class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int a=arr[i];
            for(int j=i+1;j<n;j++){
                a^=arr[j];
                int b=arr[j];
                for(int k=j;k<n;k++){
                    b^=arr[k];
                    if(a==b)ans++;
                }
            }
        }
        return ans;
    }
};

//fast O(n2)
/*
a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

Assume a == b, thus
a ^ a = b ^ a, thus
0 = b ^ a, thus
arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
prefix[k+1] = prefix[i]

We only need to find out how many pair (i, k) of prefix value are equal.
So we can calculate the prefix array first,
then brute force count the pair.

Because we once we determine the pair (i,k),
j can be any number that i < j <= k,
so we need to plus k - i - 1 to the result res.

Time O(N^2)
Space O(N)
Space O(1) if changing the input
*/
int countTriplets(vector<int>& A) {
        A.insert(A.begin(), 0);
        int n = A.size(), res = 0;
        for (int i = 1; i < n; ++i)
            A[i] ^= A[i - 1];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (A[i] == A[j])
                    res += j - i - 1;
        return res;
    }