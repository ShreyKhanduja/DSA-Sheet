
#define pii pair<int, int> // {height, isBalanced = bool}

pii balanced(TreeNode *root) {
    // base case
    if(!root)
        return {0, 1};
    // recursive calls: postorder traversal
    pii left = balanced(root->left);
    pii right = balanced(root->right);
    // height of the current node
    int height = max(left.first, right.first) + 1;
    // is the current node balanced, same for left and right subtrees
    if(left.second && right.second && abs(left.first - right.first) <= 1)
        return {height, 1};
    else    
        return {height, 0};
}

bool isBalanced(TreeNode *root) {
    return balanced(root).second;
}
