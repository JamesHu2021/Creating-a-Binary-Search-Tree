#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"

void memory_copy(void * des, const void * src, int n)
{
  char * d = des;
  const char * s = src;
  while (n--)
  {
    *d++ = *s++;
  }

  return;
}

int main() {

  char * Mystring = "This is my own memory coy function";
  char MyDes[50] = "";

  memory_copy(MyDes, Mystring, strlen(Mystring));

  printf("Source : %s\n", Mystring);
  printf("Des : %s\n", MyDes);
  return 0;
}
