class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans=0;
        unordered_map<int,int> m;
        int sum=0;
        m[0]=1;
        for(auto i:A){
            sum+=i;
            int x=sum-S;
            if(m.count(x))ans+=m[x];
            if(m.count(sum))m[sum]++;
            else m[sum]=1;
        }
        return ans;
    }
};
