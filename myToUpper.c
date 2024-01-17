#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

int my_toupper(int ch)
{
  if(islower(ch))
  {
    return ch - 'a' + 'A';
  }

  return ch;
}

int main() {

  char lowercase = 'x';
  char uppercase = my_toupper(lowercase);

  printf("Original : %c\n", lowercase);
  printf("After function calling : %c\n", uppercase);
  

  return 0;
}
