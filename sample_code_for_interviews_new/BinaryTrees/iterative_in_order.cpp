/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // LIFO used
    // Iterative order
    // left root right
public:
    vector<int> inorderTraversal(TreeNode* node) {
        vector<int> inorder_vals;
        if(node == NULL){
            return inorder_vals;
        }
        
        vector<TreeNode*> nodes;
      
        
        while(true){
            if(node != NULL){
                nodes.push_back(node);
                node = node->left;
            } else if(node == NULL){
                // all the nodes are popped off from stack
                if(nodes.size() == 0){
                    break;
                }
                
                // agar node ka left null hain
                // node top jo ki root node hain
                // usko pop karke print kar do
                // node ke right mein chale jaao
                node = nodes[nodes.size()-1];
                inorder_vals.push_back(node->val);
                nodes.pop_back();
                
                node = node->right;
            }
        }
        
        return inorder_vals;
    }
};
