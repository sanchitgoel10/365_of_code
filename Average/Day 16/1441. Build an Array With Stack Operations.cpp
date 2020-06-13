class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int ind=0;
        for(int i=1;i<=n&&ind<target.size();i++){
            if(i==target[ind]){
                v.push_back("Push");
                ind++;
            }else{
                v.push_back("Push");
                v.push_back("Pop");
            }
        }
        return v;
    }
};