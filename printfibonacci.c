
#include <stdio.h> 
#include <stdlib.h> 
// #include "list.h" 
//#include <stdlib.h>
#include <assert.h> 
struct node {
  int val;
  struct node* next;
};

struct node* createList(int nodes);
struct node* freeList(struct node* list, int nodes);

struct node* createList(int nodes) {
  int i = 0;
  struct node* list =
    (struct node*) malloc(sizeof(struct node) * nodes);
  assert(list);
  for (i = nodes - 1; i >= 0; --i) {
    list[i].val = (nodes - i) - 1;
    list[i].next = list + (i - 1);
  }
  list[0].next = NULL;
  return &list[nodes - 1];
}

struct node* freeList(struct node* list, int nodes) {
  free(&list[1 - nodes]);
}


/**
* Given a linked list of the structure:
struct node {
int val;
struct node* next;
};
print out the fibonacci nodes e.g. the 1st, 2nd, 3rd, 5th, 8th... nodes
up until the list ends.
*/

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage fib num --you gave %d args\n", argc - 1);
    // exit(0);
  }
  int nodes = 600;//atoi(argv[1]);

  if (nodes < 1) {
    printf("num must be a positive number --you gave %d\n", nodes);
  }

  struct node* list = createList(nodes);

  //Begin... 
  int prefib1 = 2;
  int prefib2 = 3;
  int curfib = 5;
  int curIndex = 1;
  struct node* listTmp = list;
  while (listTmp != NULL)
  {
    if (curIndex < 4)
    {
      printf("%d ", listTmp->val);
    }
    else if (curIndex == curfib)
    {
      printf("%d ", listTmp->val);
      prefib1 = prefib2;
      prefib2 = curfib;
      curfib = prefib1 + prefib2;
    }

    ++curIndex;
    listTmp = listTmp->next;    
  }
  //End

  freeList(list, nodes);
}

