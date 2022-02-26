#include<iostream>
#define SPACE 10
// #include <bits/stdc++.h>

using namespace std;
class TreeNode {
    public:
        int value; // aka key aka data
        TreeNode* left;
        TreeNode* right;

        TreeNode(){
            value = 0;
            left = NULL;
            right = NULL;
        }

        TreeNode(int v){
            value = v;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public:
        TreeNode* root;
        BST(){
            root = NULL;
        }
        
    bool isEmpty() {
        if(root == NULL){
            return true;
        } else{
            return false;
        }
    }
    
    // insertion in binary tree takes logn time
    // because at every juncture, we divide the search space into half 
    // based on the property of the BST
    // so if we have to insert n nodes in the BST
    // the TC will be O(nlgn)
    
    // iterative implementation of insert node
    void insertNode(TreeNode* new_node){
        if(root == NULL){
            root = new_node;
            cout << "Value Inserted as root" << endl;
        } else {
            TreeNode* temp = root;
            while(temp!= NULL) {
                if(new_node->value == temp->value){
                    cout << "This value has been inserted, insert another value" << endl;
                    return; // duplicates are not allowed
                } else if((new_node->value < temp->value) && (temp->left == NULL)) {
                    temp->left = new_node;
                    cout <<"Value Inserted at left"<< endl;
                    break;
                } else if(new_node->value < temp->value) {
                    temp = temp->left;
                } else if((new_node->value > temp->value) && (temp->right == NULL)) {
                    temp->right = new_node;
                    cout <<"Value Inserted at right"<< endl;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    
    // recursive implementation of insert node
//     BST(int value) {
//     this->value = value;
//     left = nullptr;
//     right = nullptr;
//   }

//   void insert(int value) {
//     if (value < this->value) {
//       if (left == nullptr) {
//         left = new BST(value);
//       } else {
//         left->insert(value);
//       }
//     } else {
//       if (right == nullptr) {
//         right = new BST(value);
//       } else {
//         right->insert(value);
//       }
//     }
//   }

    void print2D(TreeNode * r, int space) {
        if (r == NULL) // Base case  1
        return;
        space += SPACE; // Increase distance between levels   2
        print2D(r -> right, space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
        cout << " "; // 5.1  
        cout << r -> value << "\n"; // 6
        print2D(r -> left, space); // Process left child  7
    }

    void printPreOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        cout << root->value << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
    
    // In order traversal results in printing the tree values in
    // increasing order
    // very helpful in questions
    void printInOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        printInOrder(root->left);
        cout << root->value << " ";
        printInOrder(root->right);
    }

    void printPostOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->value << " ";
    }

    TreeNode* search(int val) {
        if(root == NULL){
            return root;
        } else {
            TreeNode* temp = root;
            while(temp != NULL){
                if(val == temp->value){
                    return temp;
                } else if(val < temp->value){
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    int height(TreeNode* root){
        if(root == NULL){
            return -1;
        } else {
            int lheight = height(root->left);
            int rheight = height(root->right);
            // adding 1 to take into account the current 1
            // instead of if else we could also do
            // max(lheight, rheight)+1
            if(lheight > rheight) {
                return lheight+1;
            } else {
                return rheight+1;
            }
        }
    }


    void printLevelOrderBfs(TreeNode* root){
        int h= height(root);
        for(int i =0; i<=h; ++i){
            printGivenLevel(root, i);
        }
    }

    void printGivenLevel(TreeNode* root, int level){
        if(root == NULL) {
            return;
        } else if(level == 0) {
            cout << root->value << " ";
        } else {
            printGivenLevel(root->left, level-1);
            printGivenLevel(root->right, level-1);
        }
    }


    TreeNode* deleteNode(TreeNode* r, int v) {
        TreeNode* temp;
        if(r == NULL){
            return r;
        } else if(v < r->value){
            r->left = deleteNode(r->left, v);
        } else if(v > r->value){
            r->right = deleteNode(r->right, v);
        } else {
            // May have 1 child or no chuld
            // child can be in r->right
            if(r->left == NULL){
                temp = r->right;
                delete r;
                return temp;
            } else if(r->right == NULL){
                // Left is not null here, because previous condition violated
                // so this is the condition of having 1 child

                temp = r->left;
                delete r;
                return temp;
            } else {
                temp = minValueNode(r->right);
                r->value = temp->value;
                // delete the duplicate node
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }

    TreeNode* minValueNode(TreeNode* r){
        TreeNode* curr = r;
        while(curr != NULL){
            curr = curr->left;
        }
        return curr;
    }

};


int main(){ 
    BST obj;
    int option, val;

    do {
        cout << "Enter the option" << "Select option Number. Enter 0 to exit" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "6. Height of the tree " << endl;
        cout << "0. Exit Program" << endl;

        TreeNode* new_node = new TreeNode();
        cin >> option;


        switch(option) {
            case 0:
                break;
            case 1:
                cout << "Insert" << endl;
                // Insertion Code
                cout << "Enter the value of the node to be inserted" << endl;
                cin >> val;
                new_node->value = val;
                obj.insertNode(new_node);
                cout << endl;
                break;
            case 2:
                cout << "Enter the value to search a node" << endl;
                // Insertion Code
                int value;
                cin >> value;
                new_node = obj.search(value);
                if(new_node != NULL){
                    cout << "Found the value" << endl;
                } else {
                    cout << "Not Found" << endl;
                }
                break;
            case 3:
                cout << "DELETE" << endl;
                cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
                cin >> val;
                new_node = obj.search(val);
                if (new_node != NULL) {
                    obj.deleteNode(obj.root, val);
                    cout << "Value Deleted" << endl;
                } else {
                    cout << "Value NOT found" << endl;
                }
                break;
            
            case 4:
                cout << "Print/Traversal BST values" << endl;
                // Insertion Code
                obj.print2D(obj.root, 5);
                cout << endl;
                obj.printPreOrder(obj.root);
                cout << endl;
                obj.printInOrder(obj.root);
                cout << endl;
                obj.printPostOrder(obj.root);
                cout << endl;
                cout << " ---------Level Order Traversal----------------" << endl;
                obj.printLevelOrderBfs(obj.root);
                cout << endl;
                break;
            case 5:
                system("clear");
                // Insertion Code
                break;
            case 6:
                int htVal;
                htVal = obj.height(obj.root);
                cout << "Height of the tree = " << htVal << endl;
            default:
                cout << "Enter Proper Option Number"<< endl ;
        }

    } while(option!=0);

    return 0;
}
