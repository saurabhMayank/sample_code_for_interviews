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


vector<int> all_traversal(TreeNode* root){
  int curr = 1;
  vector<int>preorder, inorder, postorder;
  
  vector<pair<TreeNode*, int>> nodes;
  
  nodes.push_back({root, curr});
  
  while(nodes.size() > 0){
    auto node = nodes[nodes.size()-1];
    nodes.pop_back();
    
    if(node.second == 1){
      // preorder
      preorder.push_back(node.first->val);
      int val = node.second++;
      nodes.push_back({node, val});
      
      // go left and check if node exists
      if(node->left){
        nodes.push_back({node->left, 1});
      }
    } else if(node.second == 2){
      // inorder
      inorder.push_back(node.first->val);
      int val = node.second++;
      nodes.push_back({node, val});
      
      // go right and check if node exists
      if(node->right){
        nodes.push_back({node->left, 1});
      }
    } else if(node.second == 3) {
      // postorder
      postorder.push_back(node.first->val);   
    }
    
  }
  
  return nodes;
  
}
