#include <iostream>
using namespace std;

#include <cstdio> 
/*
// 10 
// / \ 
// 5 16 
// / \ / \ 
// 3 11 14 17 
*/
struct node {
  int value;
  node * left;
  node * right;
  node * parent;

  node(int value, node * left, node * right, node * parent = NULL) : value(value), left(left), right(right), parent(parent) {}
};

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


// Test functions 

void connect_parents(node * n, node * parent) {
  if (n) {
    n->parent = parent;
    connect_parents(n->left, n);
    connect_parents(n->right, n);
  }
}

node * construct_tree() {
  node * root = new node(
    10,
    new node(5,
      new node(3, NULL, NULL),
      new node(9, NULL, NULL)),
    new node(16,
      new node(14, NULL, NULL),
      new node(17, NULL, NULL)));
  connect_parents(root, NULL);
  return root;
}

int main() {
  node * root = construct_tree();
  
  for( node * n = findMin( root ); n; n = findNext( n ) ) 
  { 
    printf( "%d ", n->value ); 
  }
  return 0;
}
