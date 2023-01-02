


bool getPath(Node* root, vector<int>&arr, int V_val){
  if(root == NULL){
    return False;
  }
  
  // push node val in arr -> res array
  arr.push_back(root->val);
  
  // root left right
  // if root val is equal to V val
  if(root->val == v_val){
    return True;
  }
  
  bool left = getPath(root->left, arr, V_val);
  bool right = getPath(root->right, arr, V_val);
  
  // if one of the left or right values are True
  if(left || right){
    return True;
  }
  
  // if one of them is also not True
  // Node V cannot be in this subtree
  // Pop the node from the path arr
  arr.pop_back();
  
  return False;
  
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(6);
  root -> left -> right -> right = newNode(7);
  root -> right = newNode(3);

  vector < int > arr;


  getPath(root, arr, 7);

  cout << "The path is ";
  for (auto it: arr) {
    cout << it << " ";
  }

  return 0;
}
