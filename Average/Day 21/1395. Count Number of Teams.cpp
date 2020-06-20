//For each soldier, count how many soldiers on the left and right have less and greater ratings.

//This soldier can form less[left] * greater[right] + greater[left] * less[right] teams.
int numTeams(vector<int>& rating) {
    int res = 0;
    for (auto i = 1; i < rating.size() - 1; ++i) {
        int less[2] = {}, greater[2] = {};
        for (auto j = 0; j < rating.size(); ++j) {
            if (rating[i] < rating[j])
                ++less[j > i];
            if (rating[i] > rating[j])
                ++greater[j > i];
        }
        res += less[0] * greater[1] + greater[0] * less[1];
    }
    return res;
}


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n=rating.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i]<rating[j]&&rating[j]<rating[k])||(rating[i]>rating[j]&&rating[j]>rating[k])){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};