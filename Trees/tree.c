#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Insert into the binary tree (basic rule: smaller left, greater right)
struct node* insert(struct node* root, int value) {
  if (root == NULL) return createNode(value);
  if (value < root->item)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);
  return root;
}

int main() {
  int n, value;
  struct node* root = NULL;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter value for node %d: ", i + 1);
    scanf("%d", &value);
    root = insert(root, value);
  }

  printf("\nInorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);

  return 0;
}
