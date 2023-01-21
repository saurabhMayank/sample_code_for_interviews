#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void reorder(node * root) {
  if (root == NULL) return;
  int child = 0; // 1
  if (root -> left) { // 2
    child += root -> left -> data;  // 3
  } // 4
  if (root -> right) { // 5
    child += root -> right -> data; // 6
  } // 7

  if (child < root -> data) { // 8
    if (root -> left) root -> left -> data = root -> data; // 9
    else if (root -> right) root -> right -> data = root -> data; // 10
  } // 11

  reorder(root -> left); // 12
  reorder(root -> right); // 13

  int tot = 0; // 14
  if (root -> left) tot += root -> left -> data; // 15
  if (root -> right) tot += root -> right -> data; // 16
  if (root -> left || root -> right) root -> data = tot; // 17
}
void changeTree(node * root) {
  reorder(root);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  changeTree(root);

  return 0;
}
