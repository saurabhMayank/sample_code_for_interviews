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
    // iterative solution
    // using stack (LIFO)
    // vector implementation of stack
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preorder_vals;
        
        if(root == NULL){
            return preorder_vals;
        }
        
        vector<TreeNode*> nodes;
        
        nodes.push_back(root);
        
        
        while(nodes.size() > 0){
            
            auto node_tmp = nodes[nodes.size()-1];
            preorder_vals.push_back(node_tmp->val);
            nodes.pop_back();
            
            if(node_tmp->right){
                nodes.push_back(node_tmp->right);
            }
            
            if(node_tmp->left){
                nodes.push_back(node_tmp->left);
            }
           
        }
        
        return preorder_vals;
    }
};
