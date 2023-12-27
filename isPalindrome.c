#include <stdio.h> 
#include <assert.h> 
#include <stdbool.h> 
#include <string.h>

// extern bool isPalindrome(const char *);
bool isPalindrome(const char *sourceString){
  //
  if (sourceString == NULL)
    return false;
  int nLen = strlen(sourceString);
  if (nLen<1)
    return false;
  int left = 0;
  int right = nLen-1;
  while (left<right) {
    int curLeft = 0;
    int curRight = 0;
    if ((sourceString[left]>'A') && (sourceString[left]<'Z'))
    {
      curLeft = sourceString[left] - 'A';
    }
    else if ((sourceString[left]>'a') && (sourceString[left]<'z'))
    {
      curLeft = sourceString[left] - 'a';
    }

    if ((sourceString[right]>'A') && (sourceString[right]<'Z'))
    {
      curRight = sourceString[right] - 'A';
    }
    else if ((sourceString[right]>'a') && (sourceString[right]<'z'))
    {
      curRight = sourceString[right] - 'a';
    }

    if (curLeft != curRight)
    {
      return false;
    }
    ++left;
    --right;

  }
  return true;
}

int main() {
  assert(isPalindrome("civic") == true);
  assert(isPalindrome("evitative") == true);
  assert(isPalindrome("radar") == true);
  assert(isPalindrome("stats") == true);
  assert(isPalindrome("abba") == true);
  assert(isPalindrome("aba") == true);
  assert(isPalindrome("aBa") == true);
  assert(isPalindrome("statss") == false);
  assert(isPalindrome("abracadabra") == false);
  printf("Lower case palindromes passed!\n");

  assert(isPalindrome("ABa") == true);
  assert(isPalindrome("cIviC") == true);
  printf("Upper/lower cases examples passed!\n");

  assert(isPalindrome("") == false);
  assert(isPalindrome(NULL) == false);
  printf("No string/empty string corner cases passed!\n");

  printf("Nailed it!! Congratulations!\n");

  return (0);
}
