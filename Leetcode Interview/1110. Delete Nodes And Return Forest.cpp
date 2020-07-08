 /*
is_root: The node's parent is deleted. The node is the root node of the tree in the forest.
!deleted: The node is not in the to_delete array.
We only need to add the root node of every tree.
*/

 vector<TreeNode*> result;
    set<int> to_delete_set;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        helper(root, result, to_delete_set, true);
        return result;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();  //delete karna hai ki nhi
        if (is_root && !deleted) result.push_back(node);                      //agar ye root hai aur delete nhi karna to push karde
        node->left = helper(node->left, result, to_delete_set, deleted);      //left tree me karke aaja kaam
        node->right =  helper(node->right, result, to_delete_set, deleted);   //right tree me karke aaja kaam
        return deleted ? NULL : node;                                         //ye node delete karna tha ki nhi
    }