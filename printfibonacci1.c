#include <stdio.h>
#include <assert.h>

// To execute C, please define "int main()"

int getFib(int n)
{
  if (n<1)
    return 0;
  if (n<3)
    return 1;

  int preFib1 = 1;
  int preFib2 = 1;
  int cur = 0;
  for (int i=3; i<=n; ++i)
  {
    cur = preFib1 + preFib2;
    preFib1 = preFib2;
    preFib2 = cur;
  }
  return cur;
}

int main() {
  for (int i = 1; i <= 30; i++) {
    printf("%d ", getFib(i));
  }

  assert(getFib(5) == 5);
  assert(getFib(10) == 55);
  assert(getFib(15) == 610);
  assert(getFib(20) == 6765);
  assert(getFib(25) == 75025);
  assert(getFib(30) == 832040);
  
  return 0;
}
