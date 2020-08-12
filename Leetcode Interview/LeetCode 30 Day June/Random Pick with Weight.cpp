/*
the pickIndex() call will have 1/(1+3+4+6) = 1/14 = ~7% chance of picking index 0; 3/14 = 21% change of picking index 1; 4/14 = 29% change of picking index 2; and 6/14 = 43% of picking index 3.
*/
class Solution {
public:
    vector<int> prefix_sum;
    Solution(vector<int>& w) {
        for (int ind : w){
            if(prefix_sum.empty())
                prefix_sum.push_back(ind);
            else
                prefix_sum.push_back(ind + prefix_sum.back());
        }
    }
    
    int pickIndex() {
        int total=prefix_sum.back();
        int index=rand()%total;
        auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(),index);
        return it - prefix_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */