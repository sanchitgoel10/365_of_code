class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for(int i=0;i<a.size();i++){
            if(!s.empty()&&s.top()>0&&a[i]<0){
                bool flag=1;
                while(!s.empty()&&s.top()>0){
                    if(abs(a[i])==abs(s.top())){
                        s.pop();
                        flag=0;
                        break;
                    }else if(abs(a[i])>abs(s.top())){
                        s.pop();
                    }else{
                        flag=0;
                        break;
                    }
                }
                if(flag)s.push(a[i]);
            }else{
                s.push(a[i]);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};