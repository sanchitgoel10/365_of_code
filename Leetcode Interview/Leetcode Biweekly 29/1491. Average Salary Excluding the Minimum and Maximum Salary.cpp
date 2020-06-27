class Solution {
public:
    double average(vector<int>& sal) {
        sort(sal.begin(),sal.end());
        int x=sal.size()-2;
        int sum=0;
        for(int i=1;i<sal.size()-1;i++){
            sum+=sal[i];
        }
        return double(sum)/double(x);
    }
};