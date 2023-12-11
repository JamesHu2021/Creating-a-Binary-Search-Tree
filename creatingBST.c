#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"

int counter = 0;

struct node{
        struct node * left;
        struct node * right;
        int value;
};

void insert(struct node * root, int key){

    ++counter;

    if(key < root->value){
        if (root->left == NULL){
            root->left = malloc(sizeof(struct node));
            root->left->value = key;
            root->left->left = NULL;
            root->left->right = NULL;
            printf("%d\n", counter);
        }
        else {
            insert(root->left, key);
        }
    }
    else {
        if (root->right == NULL){
            root->right = malloc(sizeof(struct node));
            root->right->value = key;
            root->right->left = NULL;
            root->right->right = NULL;
            printf("%d\n", counter);
        }
        else {
            insert(root->right, key);
        }
    }

}

void createBST(int keys_count, int * keys){
      struct node * treeRoot = NULL;
      counter = 0;
      for(int i = 0; i<keys_count; ++i)
      {
          int curKey = keys[i];
          if (treeRoot != NULL){
              insert(treeRoot, curKey);
          }
          else {
              treeRoot = malloc(sizeof(struct node));
              treeRoot->value = curKey;
              treeRoot->left = NULL;
              treeRoot->right = NULL;
              printf("%d\n", counter);
          }
      }
}

int main() {

      int arrayKey[3] = {1, 2, 3};
      int keyCount = 3;

      createBST(keyCount, arrayKey);

/*
  for (int i = 0; i < 5; i++) {
    printf("Hello, World\n");
  }*/
  return 0;
}
