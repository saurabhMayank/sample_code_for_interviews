// Method 1

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
    // Kth Largest -> code
    // if inorder is -> sorted array in ascending
    // kth Largest = N-k+1  where k is for kthSmalles

public:
    int kthSmallest(TreeNode* root, int k) {
      int count = 1;
      bool ele_found = false;
      
      int total_node_count = 0;
      count_total_nodes(root, total_node_count);
        
      // tweaking kth smallest node for kth largest
      k = total_node_count-k+1;
      
        
      TreeNode*kth_node = kthSmallestHelperNode(root, k, count, ele_found);
      return kth_node->val;
    }
    
    void count_total_nodes(TreeNode* root, int& total_node_count){
        if(root == NULL){
            return;
        }
        count_total_nodes(root->left, total_node_count);
        total_node_count++;
        count_total_nodes(root->right, total_node_count);
        return;
    }
    
    TreeNode* kthSmallestHelperNode(TreeNode* root, int k, int& count, bool& ele_found){
        if(root == NULL){
            return NULL;
        }
        

        TreeNode* left_node = kthSmallestHelperNode(root->left, k, count, ele_found);
        if(count == k && ele_found){
            return left_node;
        }
        
        if(count == k && !ele_found){
            ele_found = true;
            return root;
        } else if(ele_found){
            return root;
        } else {
            count++;
        }
        
        TreeNode* right_node = kthSmallestHelperNode(root->right, k, count, ele_found);
        if(count == k && ele_found){
            return right_node;
        }
        
        return root;
    }
};


// Method -> 2
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
    // Kth Largest -> code
   // reverse order of kth smallest node
  // traverse in the order of right, root, left
  // rest all the code same as kth smallest

public:
    int kthSmallest(TreeNode* root, int k) {
      int count = 1;
      bool ele_found = false;
      
      // int total_node_count = 0;
      // count_total_nodes(root, total_node_count);
        
      // tweaking kth smallest node for kth largest
      // k = total_node_count-k+1;
      
        
      TreeNode*kth_node = kthSmallestHelperNode(root, k, count, ele_found);
      return kth_node->val;
    }
    
    // void count_total_nodes(TreeNode* root, int& total_node_count){
    //     if(root == NULL){
    //         return;
    //     }
    //     count_total_nodes(root->left, total_node_count);
    //     total_node_count++;
    //     count_total_nodes(root->right, total_node_count);
    //     return;
    // }
    
    TreeNode* kthSmallestHelperNode(TreeNode* root, int k, int& count, bool& ele_found){
        if(root == NULL){
            return NULL;
        }
        

        TreeNode* left_node = kthSmallestHelperNode(root->right, k, count, ele_found);
        if(count == k && ele_found){
            return left_node;
        }
        
        if(count == k && !ele_found){
            ele_found = true;
            return root;
        } else if(ele_found){
            return root;
        } else {
            count++;
        }
        
        TreeNode* right_node = kthSmallestHelperNode(root->left, k, count, ele_found);
        if(count == k && ele_found){
            return right_node;
        }
        
        return root;
    }
};
