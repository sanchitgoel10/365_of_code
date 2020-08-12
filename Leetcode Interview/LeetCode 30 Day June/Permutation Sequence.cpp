class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        --k;  //index  0 based karna hai
        for (int i = n; i >= 1; --i) {
            int j=k/f[i-1];
            k-=j*f[i-1];
            res.push_back(nums[j]);
            nums.erase(nums.begin() + j);    //O(n) operation
        }
        return res;
    }
};