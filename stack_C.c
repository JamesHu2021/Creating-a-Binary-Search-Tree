#include <stdio.h>

// given stack data type stackElementT
// define a stackT with functions

#include <stdlib.h>
#include <stdbool.h>

typedef char stackElementT;

// with maxsize
typedef struct stackT{
  stackElementT *val;
  int top;
  int maxsize;
} stackT;

void initStack(stackT * stack, int maxSize){
  stack->val = (stackElementT *)malloc(sizeof(struct stackT)*maxSize);
  stack->top = -1;
  stack->maxsize = maxSize;
}

void freeStack(stackT * stack){
  if (stack)
  {
    free(stack->val);
    stack->top = -1;
    stack->maxsize = 0;
  }
}

bool isEmpty(stackT * stack){
  return stack->top == -1;
}

bool isFull(stackT * stack){
  return stack->top == (stack->maxsize-1);
}

void push(stackT * stack, stackElementT curElement){
  if (isFull(stack))
  {
    printf("Stack is full\n");
    return;
  }
  stack->val[++stack->top] = curElement;
}

stackElementT pop(stackT * stack){
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    exit(EXIT_FAILURE);
  }

  return stack->val[stack->top--];
}

stackElementT peek(stackT * stack){
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    exit(EXIT_FAILURE);
  }
  return stack->val[stack->top];
}

// To execute C, please define "int main()"

int main() {

  stackT myStack;
  const int nMaxSize = 5;
  initStack(&myStack, nMaxSize);
  push(&myStack, 'A');
  push(&myStack, 'B');
  push(&myStack, 'C');
  push(&myStack, 'D');

  printf("Top element 1: %c\n", peek(&myStack));
  pop(&myStack);
  printf("Top element 2: %c\n", peek(&myStack));
  pop(&myStack);
  printf("Top element 3: %c\n", peek(&myStack));
  pop(&myStack);
  printf("Top element 4: %c\n", peek(&myStack));

  freeStack(&myStack);


  /*for (int i = 0; i < 5; i++) {
    printf("Hello, World\n");
  }*/
  return 0;
}
