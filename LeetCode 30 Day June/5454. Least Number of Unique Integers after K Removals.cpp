class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto i:arr)m[i]++;
        vector<int> freq;
        for(auto i:m){
            freq.push_back(i.second);
        }
        int ans=m.size();
        sort(freq.begin(),freq.end());
        for(auto i:freq){
            if(k==0||k<i)return ans;
            k-=i;
            ans--;
        }
        return ans;
    }
};