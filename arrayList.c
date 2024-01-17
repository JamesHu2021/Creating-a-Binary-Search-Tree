#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int * array;
  size_t size;
  size_t capacity;
} ArrayList;

void initArrayList(ArrayList * List, size_t initCapacity)
{
  int * Tmp = malloc(sizeof(int)*initCapacity);
  if (Tmp == NULL)
  {
    printf("Malloc memory failed.\n");
    exit(-1);
  }
  List->array = Tmp;
  List->size = 0;
  List->capacity = initCapacity;
}

void appendValue(ArrayList * List, int value)
{
  if (List->size == List->capacity)
  {
    int * NewArray = realloc(List->array, sizeof(int)*List->capacity*2);
    if (NewArray == NULL)
    {
      printf("Realloc memory failed\n");
      exit(-1);
    }
    List->array = NewArray;
    List->capacity = 2*List->capacity;
  }
  List->array[List->size++] = value;
}

int getValue(ArrayList * List, size_t index)
{
  if (index >= List->size)
  {
    printf("Index is out of bound of the array.");
    exit(-1);
  }
  return (List->array[index]);
}

void freeArray(ArrayList * List)
{
  free(List->array);
  List->size = 0;
  List->capacity = 0;
}

int main() {

  ArrayList myList;
  initArrayList(&myList, 5);
  for (int i = 0; i<10; i++)
  {
    appendValue(&myList, i);
  }

  printf("The 9 item in my arraylist is %d", getValue(&myList, 8));
  
  return 0;
}
