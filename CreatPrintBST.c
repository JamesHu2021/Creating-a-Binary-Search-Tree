#include <stdio.h> 
#include <stdlib.h>
#include <stddef.h>

/* Example BST:
*
* 8
* / \
* 4 12
* / \ / \
* 1 7 11 20
*/


typedef struct node {
  int value;
  struct node *left, *right, *parent;
} node_t;

struct node * findMin(struct node *n) {
  for (; n && n->left; n = n->left);
  return n;
}

struct node * findNext(struct node *n) {
  if (n->right) {
    return findMin(n->right);
  }
  else {
    for (; n->parent; n = n->parent) {
      if (n->parent->left == n) {
        return n->parent;
      }
    }
    return NULL;
  }
}

/* print the bst in-order */
void printBst(struct node *n) {
    if (n->left) {
        printBst(n->left);
    }
    printf("%d ", n->value);
    if (n->right) {
        printBst(n->right);
        
    }
}
    
    void printBstNR(struct node *root) {
        node_t* n;
        for (n = findMin(root); n; n = findNext(n)) {
            printf("%d ", n->value);
        }
    }
    
    node_t* insertNode(node_t** root, int newval)
    {
        node_t *n;
        if (!(*root)) {
            n = (node_t*)calloc(1, sizeof(node_t));
            n->value = newval;
            *root = n;
        }
        else if (newval < (*root)->value) {
            n = insertNode(&((*root)->left), newval);
            if ((*root)->left == n) n->parent = *root;
        }
        else {
            n = insertNode(&((*root)->right), newval);
            if ((*root)->right == n) n->parent = *root;
        }
        return n;
    }

    int main()
    {
        node_t* root = NULL;
        int data[] = { 8, 4, 12, 1, 7, 11, 20 };
        int i, len = sizeof(data) / sizeof(int);
        
        for (i = 0; i < len; i++) insertNode(&root, data[i]);
        
        printf("\ntraversal w/o recursion: ");
        printBstNR(root);
        printf("\ntraversal w/o recursion: ");
        printBstNR(root);
        
        printf("\ntraversal w/ recursion: ");
        printBst(root);
        printf("\n");
        return 0;
    }
