class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        for(int i=0;i<s.size();i++){
            if(!stk.empty()&&stk.top().second==k){
                int x=k;
                while(x){
                    stk.pop();
                    x--;
                }
            }
            if(stk.empty()){
                stk.push({s[i],1});
            }else{
                if(stk.top().first==s[i]){
                    stk.push({s[i],stk.top().second+1});
                }else{
                    stk.push({s[i],1});
                }
            }
            //cout<<stk.top().first<<" "<<stk.top().second<<endl;
        }
        if(!stk.empty()&&stk.top().second==k){
            int x=k;
            while(x){
                stk.pop();
                x--;
            }
        }
        string ans="";
        while(!stk.empty()){
            auto x=stk.top();
            stk.pop();
            ans+=x.first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};