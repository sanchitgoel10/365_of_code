class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& cs) {
        vector<vector<int>> res(2, vector<int>(cs.size()));
        for (auto i = 0; i < cs.size(); u -= res[0][i], l -= res[1][i++]) {
            res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u); //greedy
            res[1][i] = cs[i] == 2 || (cs[i] == 1 && l >= u );
        }
        return u == 0 && l == 0 ? res : vector<vector<int>>();    //upper and lower should be fully used
    }
};