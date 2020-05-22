
//First normal pq solution

class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        if(n==0)return s;
        unordered_map<char,int> m;
        for(auto i:s){
            if(m.count(i))m[i]++;
            else m[i]=1;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        string ans;
        while(!pq.empty()){
            int t=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            while(t--){
                ans.push_back(c);
            }
        }
        return ans;
    }
};

//O(n) bucket sort with way to extra space 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};