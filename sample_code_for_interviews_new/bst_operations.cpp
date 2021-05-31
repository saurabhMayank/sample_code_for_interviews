#include<iostream>
#define SPACE 10

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
                } else if((new_node->value < temp->value) &&
                        (temp->left == NULL)) {
                        temp->left = new_node;
                        cout <<"Value Inserted at left" << endl;
                        break;
                } else if(new_node->value < temp->value) {
                    temp = temp->left;
                } else if((new_node->value > temp->value) &&
                    temp->right == NULL) {
                        temp->right = new_node;
                        cout <<"Value Inserted at right" << endl;
                        break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }

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
                cout << "Search Node" << endl;
                // Insertion Code
                break;
            case 3:
                cout << "Delete Node" << endl;
                // Insertion Code
                break;
            
            case 4:
                cout << "Print/Traversal BST values" << endl;
                // Insertion Code
                obj.print2D(obj.root, 5);
                break;
            case 5:
                system("clear");
                // Insertion Code
                break;
            default:
                cout << "Enter Proper Option Number"<< endl ;
        }

    } while(option!=0);

    return 0;
}