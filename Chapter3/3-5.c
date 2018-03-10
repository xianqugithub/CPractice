#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char[]);

main()
{
  int n = -12345;
  char s[1000];
  int b = 16;
  itob(n, s, b);
  printf("%s\n", s);
}



void itob(int n, char s[], int b)
{
  int sign, i;
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    int cur = n % b;
    if (b > 10 && cur > 10)
      cur = cur - 10 + 'a';
    else
      cur = cur + '0';
    s[i++] = cur;
  } while ( (n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[])
{
  int i, j, c;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }

}

