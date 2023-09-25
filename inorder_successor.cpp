
Node *inOrderSuccessor(Node *root, int x) {
    Node *succ = NULL;
    while(root) {
        if(root->data > x->data) {
            succ = root;
            // x will lie in the left subtree
            root = root->left;
        }
        else    
            root = root->right;
    }
    return succ;
}