
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    // helper function
    void inorder(TreeNode *root) {
        // push all the left most nodes
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        // pop the top node
        TreeNode *top = s.top();
        s.pop();
        // make a call to the right node
        inorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */