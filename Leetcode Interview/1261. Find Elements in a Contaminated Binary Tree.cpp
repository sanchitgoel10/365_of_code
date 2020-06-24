//Smart way

class FindElements {
public:
    unordered_set<int> s;
    void fill(TreeNode*root,int v){
        root->val=v;
        s.insert(v);
        if(root->left)fill(root->left,2*v+1);
        if(root->right)fill(root->right,2*v+2);
    }
    
    FindElements(TreeNode* root) {
        fill(root,0);
    }
    bool find(int target) {
        return s.count(target);
    }
};

//Ordinary way

class FindElements {
public:
    TreeNode* Root;
    void fill(TreeNode*root,int v){
        root->val=v;
        if(root->left)fill(root->left,2*v+1);
        if(root->right)fill(root->right,2*v+2);
    }
    
    FindElements(TreeNode* root) {
        Root=root;
        fill(root,0);
    }
    
    bool get(TreeNode*root,int t){
        if(root->val==t)return 1;
        bool a=0,b=0;
        if(root->left) a=get(root->left,t);
        if(root->right) b=get(root->right,t);
        return a|b;
    }
    
    bool find(int target) {
        return get(Root,target);
    }
};
