#include <stdio.h>

void reverse(char s[], int i, int len)
{
  int j, c;
  j = len - i - 1;

  if (i < j) {
    c = s[i];
    s[i] = j;
    s[j] = c;
    reverse(s, ++i, len);
  }
  
}
