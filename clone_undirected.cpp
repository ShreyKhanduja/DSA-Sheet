
class Solution {
public:
    // helper function
    void dfs_helper(Node *node, Node *copy, vector<Node*> &created) {
        // store the pointer to the current copy node
        created[copy->val] = copy;
        // iterate through the adjacent nodes
        for(auto nbr : node->neighbors) {
            // if the neighbor node is not previously visited, create a new node
            if(!created[nbr->val]) {
                Node *new_node = new Node(nbr->val);
                // push this neighbor node in the neighbors vector of copy node
                (copy->neighbors).push_back(new_node);
                // init a recursive dfs call
                dfs_helper(nbr, new_node, created);
            }
            else 
                (copy->neighbors).push_back(created[nbr->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        // edge case
        if(!node) 
            return NULL;
        
        vector<Node*> created(101, NULL);
        Node *copy = new Node(node->val);
        dfs_helper(node, copy, created);
        
        return copy;
    }
};