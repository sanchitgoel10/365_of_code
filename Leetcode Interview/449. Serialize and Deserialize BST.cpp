/*Sharing my solution which doesn't have to parse string for comma at all!

The encoding schema is preorder of BST, and to decode this we can use the same preorder traversal to do it in one pass with recursion in O(n) time.

To minimize the memory, I used binary format instead of ascii format for each integer, just burn those int into 4 chars will save you a lot!!!

Really if using ASCII numbers you are paying a lot of penalty memory for integers over 4 digit long and parsing comma is just as painful.
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        preorderDFS(root, order);
        return order;
    }
    
    inline void preorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[sizeof(int)];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        preorderDFS(root->left, order);
        preorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
    
    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};