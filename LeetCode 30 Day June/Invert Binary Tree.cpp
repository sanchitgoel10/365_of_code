
/*
 Recursion is not good way to go due to performance overhead and risk to run it against huge tree. With standard queue solution looks simple robust and runs faster.
 */


//TreeNode* invertTree(TreeNode* root) {
    
    if(nullptr == root) return root;
    
    queue<TreeNode*> myQueue;   // our queue to do BFS
    myQueue.push(root);         // push very first item - root

    while(!myQueue.empty()){    // run until there are nodes in the queue 
        
        TreeNode *node = myQueue.front();  // get element from queue
        myQueue.pop();                     // remove element from queue
                 
        if(node->left != nullptr){         // add left kid to the queue if it exists
            myQueue.push(node->left);
        }
        
        if(node->right != nullptr){        // add right kid 
            myQueue.push(node->right);
        }
        
        // invert left and right pointers      
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;

    }

    return root;
}

//Recursive

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        swap(root->right,root->left);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};