#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

char *strdup(const char *s);

char rotate(const char in, char pivot, int offset)
{
  return pivot + (in - pivot + offset) % 26;
}

void caesar(const char *in, char *outbuf, int offset)
{
  // int i;
  char *out = outbuf;
  for (; *in; ++in, ++out) {
    if (*in >= 'A' && *in <= 'Z')
      *out = rotate(*in, 'A', offset);
    else if (*in >= 'a' && *in <= 'z')
      *out = rotate(*in, 'a', offset);
    else
      *out = *in;
  }
  *out = 0;
}



int
main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
    // return 1;
  }

  char *buf = strdup("Test String for caesar."); //strdup(argv[1]);

  if (buf == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    return 1;
  }

  caesar(buf, buf, 13);
  printf("%s\n", buf);

  if (buf != NULL) {
    free(buf);
  }

  return 0;
}
