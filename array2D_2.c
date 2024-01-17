#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int rows;
  int cols;
  int ** array;
} Array2D;

Array2D createArray(int Row, int Col)
{
  Array2D myArray2D;
  myArray2D.rows = Row;
  myArray2D.cols = Col;
  myArray2D.array = malloc(sizeof(int *)* Row);
  if (myArray2D.array == NULL)
  {
    printf("Malloc memory failed 1.\n");
    exit(-1);
  }

  for (int i = 0; i<Row; ++i)
  {
    int *tmp = malloc(sizeof(int)*Col);
    if (tmp == NULL)
    {
      printf("Malloc memory failed 2.\n");
      exit(-1);
    }
    myArray2D.array[i] = tmp;
  }

  return myArray2D;
}

void freeArray(Array2D myArray2D)
{
  for (int i = 0; i<myArray2D.rows; ++i)
  {
    free(myArray2D.array[i]);
  }
  free(myArray2D.array);
}


int main() {

  int row = 3;
  int col = 4;

  Array2D myArray = createArray(row, col);

  for (int i = 0; i<row; ++i)
  {
    for (int j = 0; j<col; ++j)
    {
      myArray.array[i][j] = i*col + j;
    }
  }

  for (int i = 0; i<row; ++i)
  {
    for (int j = 0; j<col; ++j)
    {
      printf("%d ", myArray.array[i][j]);
    }
    printf("\n");
  }

  return 0;
}
