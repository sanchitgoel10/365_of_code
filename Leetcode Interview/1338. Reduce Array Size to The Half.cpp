class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int> p;
        unordered_map<int,int> cnt;
        for(auto i:arr)cnt[i]++;
        for(auto x:cnt){
            p.push(x.second);
        }
        int n=arr.size();
        int removed=0,ans=0;
        while(removed<(n/2)){
            removed+=p.top();
            p.pop();
            ans++;
        }
        return ans;
    }
};