//First the next permuatation approach below I have also included recursive approach
//n! times since all digits are distinct
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        for (int i = 0, n = factorial(nums.size()); i < n; i++) {
            perms.push_back(nums);
            nextPermutation(nums);
        }
        return perms;
    }
private:
    int factorial(int n) {
        int f = 1;
        while (n > 1) {
            f *= n--;
        }
        return f;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};



/*
The idea is much like the insertion sort. We start with only the first number, and pick next number from the rest of array, insert it to the front or back position of the first number, and pick the third number, insert it to front or mid or back position of the [first, second] array, and so on, until no element left.
For example, given array [1,2,3].
First, we have [1] as array to be inserted, and [2,3] remain;
next number is 2, we insert it to the front or back of [1], which become [1,2] and [2,1], with [3] remain.
Then we pick number 3, insert it to [1,2] and [2,1],
Insert to front position, we get
[3,1,2],
[3,2,1]
Insert to mid position, we get
[1,3,2],
[2,3,1],
Insert to back, we get
[1,2,3],
[2,1,3],
and no element left in remain array, finish.
Here is my code,

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>vec;
        DFS(nums, 0, vec, res);
        return res;
    }
    
    void DFS(vector<int>& nums, int pos, vector<int>& vec, vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i = 0; i <= vec.size(); i++){
            vec.insert(vec.begin() + i, nums[pos]);
            DFS(nums, pos + 1, vec, res);
            vec.erase(vec.begin() + i);
        }
        return;
    }
};
Update(9/2/2017): No more insert and erase, my updated solution with swap.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        DFS(res, nums, 0);
        return res;        
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos){
        if(pos == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            swap(nums[pos], nums[i]);
            DFS(res, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};
*/