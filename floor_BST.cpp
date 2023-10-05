
int floor(Node *root, int key) {
    int floor_val = -1;
    while(root) {
        if(root->data == key)
            return key;
        else if(root->data > key) 
            root = root->left;
        else {
            floor_val = root->data;
            root = root->right;
        }
    }
    return floor_val;
}