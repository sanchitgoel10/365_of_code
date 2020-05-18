class Solution {
public:
    string reorganizeString(string S) {
        int n=S.size();
        int map[26]={0};
        for(auto i:S){
            if(++map[i-'a']>(n+1)/2)return "";     //t is easy to see that if N is the length of the string, and the count of some letter is greater than (N+1) / 2, the task is impossible.
        }
        priority_queue<pair<int, char> > pq;
        for(int i=0;i<26;i++){
            if(map[i]){
                pq.push({map[i],i+'a'});
            }
        }
        string ans;
        while(!pq.empty()){
            pair<int,char>p1,p2;       //play with the topmost 2 again and again
            p1=pq.top();
            pq.pop();
            ans.push_back(p1.second);
            if(!pq.empty()){
                p2=pq.top();
                pq.pop();
                ans.push_back(p2.second);
                if(--p2.first){             //ek count kam karke daal diya wapis if 0 nahi hai count
                    pq.push(p2);
                }
            }
            if(--p1.first){
                pq.push(p1);          //same upar ki tarah yaha 
            }
        }
        return ans;
    }
};