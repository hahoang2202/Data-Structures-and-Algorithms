#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key){
  if(node == NULL) return newNode(key);
  if(key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}


struct node* search(struct node* root, int key){
	if (root == NULL || root->key == key) return root;
	if (root->key < key) return search(root->right, key);
	return search(root->left, key);
}

int main(){
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
  
  printf("\nInorder traversal: ");
  inorder(root);
  
  root = search(root, 6);
  if(root == NULL) printf("\nKhông có phần tử!");
  else printf("\nCó phần tử!");
}
