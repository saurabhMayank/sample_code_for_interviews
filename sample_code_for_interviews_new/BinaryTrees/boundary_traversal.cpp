//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector <int> boundary(Node *root){
        //Your code here
        // root node NULL
        if(!root) return {};
        vector<int> res;
        
        // root node represents leaf
        // left child and right child does not exist
        if(!isleaf(root))res.push_back(root->data); 
        
        // traverse and store the left boundary without leaves
        left_boundary_traversal(root, res);
            
        // traverse and store the leaves
        leaves_traversal(root, res);
            
        // traverse and store the right boundary without leaves
        right_boundary_traversal(root, res);
       
        
        return res;
    }
    
    void left_boundary_traversal(Node* root, vector<int> &res){
        if(!root){
            return;
        }
        // so that root node is not traversed again
        Node* curr = root->left;
        while(curr){
            // if leaf node comes break and return
            if(isleaf(curr)) break;
            res.push_back(curr->data);
            
             // till left node exists go left
            if(curr->left){
                curr = curr->left;
            }else {
                // if left node is empty then go right
                curr = curr->right;
            }
        }
    }
    
    // store the right boundary in reverse order
    void right_boundary_traversal(Node* root, vector<int> &res){
        if(!root){
            return;
        }
        vector<int> temp;
        // so that root node is not traversed again
        Node* curr = root->right;
        while(curr){
            // if leaf node comes break and return
            if(isleaf(curr)) break;
            temp.push_back(curr->data);
            
             // till right node exists go right
            if(curr->right){
                curr = curr->right;
            }else {
                // if right node is empty then go left
                curr = curr->left;
            }
        }
        
        while(temp.size()!= 0){
            int val = temp[temp.size()-1];
            res.push_back(val);
            temp.pop_back();
        }
        
    }
    
    void leaves_traversal(Node* root, vector<int> &res){
        if(!root){
            return;
        }
        
        // Inorder traversal
        if(root->left){
            leaves_traversal(root->left, res);
        }
        if(isleaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->right){
            leaves_traversal(root->right, res);
        }
        return;
    }
    
    bool isleaf(Node* node){
        if(!node->left && !node->right){
            return true;
        }else {
            return false;
        }
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
