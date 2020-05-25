/*
Intuition
The necessar and suffisant condition of pseudo-palindromic,
is that at most one digit has odd occurrence.


Solution 1: Use Array
Recursively iterate all paths from root to leaves,
count the occurrence of each digits in an array.
At the leaf node, check if at most one digit has odd occurrence.

Time O(NK)
Space O(K + H)
where K is the number of different elements,
H is the height.
In this problem, K = 9


Solution 2: Use HashSet
Recursively iterate all paths from root to leaves,
count the occurrence of each digits in an hashset.

Whenever meet an element, toggle it in the set:
If set contains it, remove it.
If set donesn't contain it, add it.

At the leaf node, check if the size of set <= 1.

Time O(N)
Space O(K + H)


Solution 3: Use an integer
Recursively iterate all paths from root to leaves,
count the occurrence of each digits in an integer.

Use this integer as a bit mask.
Also c++, we can use bitmask directly.

Whenever meet an element,
toggle the corresponding bit using ^ operation.

At the leaf node,
check if the count has only one bit that is 1.

We use lowbit to help count this.
Google it if you don't know.

Time O(N)
Space O(K + H)
*/
 int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int count) {
        if (!root) return 0;
        count ^= 1 << (root->val);        //vo wali bit set kardi ..
        int res = dfs(root->left, count) + dfs(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;    //root->left==root->right is condition for leaf node
        return res;
    }