#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_INITIAL_CAPACITY 10

typedef struct {
  void ** data;
  size_t top;
  size_t capacity;
} Stack;

int initStack(Stack * stack)
{
  stack->data = malloc(STACK_INITIAL_CAPACITY * sizeof(void *));
  if (stack->data == NULL)
  {
    printf("Memory allocation failed.\n");
    return -1;
  }
  stack->top = 0;
  stack->capacity = STACK_INITIAL_CAPACITY;
  return 0;
}

int push(Stack * stack, void * element){
  if (stack->top == stack->capacity)
  {
    stack->capacity *= 2;
    void * tmp = realloc(stack->data, stack->capacity * sizeof(void *));
    if (tmp == NULL)
    {
      printf("Memory reallocation failed. Can not push more elements.\n");
      stack->capacity /= 2;
      return -1;
    }
    //
    stack->data = tmp;
  }

  stack->data[stack->top++] = element;

  return 0;

}

//another push()
int push1(Stack * stack, void * element){
  if (stack->top == stack->capacity)
  {
    void ** originalData = stack->data;
    size_t originalTop = stack->top;
    size_t originalCapacity = stack->capacity;

    stack->capacity *= 2;
    stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
    if (stack->data == NULL)
    {
      printf("Memory reallocation failed. Can not push more elements.\n");
      stack->data = originalData;
      stack->top = originalTop;
      stack->capacity = originalCapacity;
      return -1;
    }
  }

  stack->data[stack->top++] = element;

  return 0;

}

int pop(Stack * stack){
  if(stack->top > 0)
  {
    stack->top--;
  }
  else {
    printf("Stack is empty. Can not pop any element.\n");
    return -1;
  }
  return 0;
}

void * top(const Stack * stack){
  if (stack->top>0)
  {
    return stack->data[stack->top-1];
  }
  else {
    printf("Stack is empty. Can not get the top element.\n");
    return NULL;
  }
}

bool isEmpty(const Stack * stack)
{
  return stack->top == 0;
}

void freeStack(Stack * stack)
{
  free(stack->data);
  stack->top = 0;
  stack->capacity = 0;
}



int main() {

  Stack myStack;
  initStack(&myStack);
  
  int num1 = 42;
  double num2 = 3.14;
  char ch = 'A';

  push1(&myStack, &num1);
  push1(&myStack, &num2);
  push1(&myStack, &ch);

  printf("Top element : %c\n", *(char *)top(&myStack));

  pop(&myStack);

  printf("Top element : %lf\n", *(double *)top(&myStack));

  pop(&myStack);

  printf("Top element : %d\n", *(int *)top(&myStack));

  freeStack(&myStack);

  return 0;
}
