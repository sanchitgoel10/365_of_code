/*
optimized for memory use as we only need to keep track of the previous i-th-minus-1 hop values ( i.e. use a "sliding window" of size 2 ).
{ 4, 6 },  { 6, 8 },  { 7, 9 },  { 4, 8 },  { 0, 3, 9 },  { },  { 0, 1, 7 },  { 2, 6 },  { 1, 3 },  { 2, 4 }
0 pe 4 aur 6 se aa sakte hai 1 pe 6 aur 8 se aa sakte hai similarly baaki
*/
class Solution {
public:
    const int mod=1e9+7;
    int knightDialer(int N) {
        vector<long> curr(10,1),next(curr);
        for(int i=2;i<=N;i++){
            next[0]=(curr[4]+curr[6])%mod;
            next[1]=(curr[6]+curr[8])%mod;
            next[2]=(curr[7]+curr[9])%mod;
            next[3]=(curr[4]+curr[8])%mod;
            next[4]=(curr[0]+curr[3]+curr[9])%mod;
            next[5]=(0);
            next[6]=(curr[0]+curr[1]+curr[7])%mod;
            next[7]=(curr[2]+curr[6])%mod;
            next[8]=(curr[1]+curr[3])%mod;
            next[9]=(curr[2]+curr[4])%mod;
            curr.swap(next);
        }
        return accumulate(curr.begin(),curr.end(),0L)%mod;
    }
};