class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string start="";
        for(auto i:board){
            for(auto j:i){
                start+=to_string(j);
            }
        }
        //cout<<start<<endl;
        vector<vector<int>> dirs={ { 1, 3 }, { 0, 2, 4 },
                { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
        queue<string> q;
        set<string> vis;
        vis.insert(start);
        q.push(start);
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string curr=q.front();
                q.pop();
                //cout<<curr<<" ";
                if(curr==target)return ans;
                int ind=curr.find('0');
                //cout<<ind<<endl;
                for(auto d:dirs[ind]){
                    string next=curr;
                    swap(next[ind],next[d]);
                    //cout<<next<<endl;
                    if(vis.find(next)==vis.end()){q.push(next),vis.insert(next);};
                }
            }
            //cout<<endl;
            ans++;
        }
        return -1;
    }
};