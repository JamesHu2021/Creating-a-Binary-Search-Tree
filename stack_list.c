#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef int SDataType;
typedef struct stack{
  SDataType data;
  struct stack * next;
} ST;

bool StackIsEmpty(ST ** top){
  return ((*top) == NULL);
}

void StackDestroy(ST ** top){

  ST * cur = *top;
  while (cur) {
    ST * next = cur->next;
    free(cur);
    cur = next;
  }
}

void StackPush(ST ** top, SDataType x){
  assert(top);//? 如果传的是指针变量的值，报错
  ST * newNode = malloc(sizeof(ST));
  if (newNode == NULL)
  {
    printf("Malloc fail.\n");
    exit(-1);
  }
  newNode->data = x;
  newNode->next = NULL;

  if (*top == NULL)
  {
    *top = newNode;
  }
  else {
    newNode->next = *top;
    *top = newNode;
  }

}

void StackPop(ST ** top){
  assert(!StackIsEmpty(top));

  if ((*top)->next == NULL){
    free(*top);
    *top = NULL;
  }
  else {
    ST * prev = (*top)->next;
    free(*top);
    *top = prev;
  }
}

SDataType StackTop(ST ** top){
  assert(!StackIsEmpty(top));
  return (*top)->data;
}

int StackSize(ST ** top){
  if (StackIsEmpty(top))
    return 0;

  int count = 1;
  ST * cur = *top;
  while (cur->next)
  {
    cur = cur->next;
    count++;
  }
  return count;
}


int main() {

  ST * ps = NULL;
  StackPush(&ps, 1);
  printf("Top value : %d\n", StackTop(&ps));
  StackPush(&ps, 2);
  printf("Top value : %d\n", StackTop(&ps));
  StackPush(&ps, 3);
  printf("Top value : %d\n", StackTop(&ps));
  StackPush(&ps, 4);
  printf("Top value : %d\n", StackTop(&ps));
  StackPush(&ps, 5);
  printf("Top value : %d\n", StackTop(&ps));
  StackPush(&ps, 6);
  printf("Top value : %d\n", StackTop(&ps));
  StackPop(&ps);
  StackPop(&ps);
  printf("Top value : %d Total Size: %d\n", StackTop(&ps), StackSize(&ps));
  StackPush(&ps, 7);
  StackPush(&ps, 8);
  printf("Top value : %d Total Size: %d\n", StackTop(&ps), StackSize(&ps));
  StackPop(&ps);
  StackPop(&ps);
  StackPop(&ps);
  StackPop(&ps);
  StackPop(&ps);
  printf("Top value : %d Total Size: %d\n", StackTop(&ps), StackSize(&ps));
  StackPop(&ps);
  printf("Total Size: %d\n", StackSize(&ps));

  StackDestroy(&ps);

  return 0;
}
