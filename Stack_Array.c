#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int STDataType;

typedef struct stack{
  STDataType * a;
  int top;
  int capacity;
} ST;

void StackInit(ST * ps){
  ps->a = NULL;
  ps->top = 0;
  ps->capacity = 0;
}

void StackDestroy(ST * ps){
  if (ps->a)
  {
    free(ps->a);
  }

  ps->a = NULL;
  ps->capacity = ps->top = 0;
    
}

int StackSize(ST * ps){
  return ps->top;
}

bool StackisEmpty(ST * ps){
  return (ps->top == 0);
}

void StackPush(ST * ps, STDataType x){
  if (ps->top == ps->capacity)
  {
    int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity*2;
    STDataType * tmp = realloc(ps->a, sizeof(STDataType)*newCapacity);
    if (tmp == NULL)
    {
      printf("Realloc fail\n");
      exit(-1);
    }
    ps->a = tmp;
    ps->capacity = newCapacity;
  }
  ps->a[ps->top++] = x;
}

void StackPop(ST * ps){
  assert(!StackisEmpty(ps));
  ps->top--;
}

STDataType StackTop(ST * ps){
  assert(!StackisEmpty(ps));
  return ps->a[ps->top-1];
}


int main() {
  ST myStack;
  StackInit(&myStack);
  StackPush(&myStack, 1);
  StackPush(&myStack, 2);
  StackPush(&myStack, 3);
  StackPush(&myStack, 4);
  StackPush(&myStack, 5);

  printf("Stack size is %d, Top item : %d\n", StackSize(&myStack), StackTop(&myStack));

  StackPop(&myStack);
  StackPop(&myStack);

  printf("Stack size is %d, Top item : %d\n", StackSize(&myStack), StackTop(&myStack));

  StackPush(&myStack, 6);
  StackPush(&myStack, 7);

  printf("Stack size is %d, Top item : %d\n", StackSize(&myStack), StackTop(&myStack));

  return 0;
}
