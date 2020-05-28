Recursive

//Similar to a level-order traversal, even you are not allowed to use a queue, the next pointer provides you with a way to move to the next node in //the same level.

class Solution {
public:
    Node* connect(Node* root) {
        Node *pre = root, *cur;
        while (pre) {
            cur = pre;
            while (cur && cur -> left) { 
                cur -> left -> next = cur -> right;
                if (cur -> next) {
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            pre = pre -> left;
        }
        return root;
    }
};
//Recursive

//Recursively connect the left and right subtrees.

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        if (root -> left) {
            root -> left -> next = root -> right;
            if (root -> next) {
                root -> right -> next = root -> next -> left;
            }
            connect(root -> left);
            connect(root -> right);
        }
        return root;
    }
};