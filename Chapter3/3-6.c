#include <stdio.h>
#include <string.h>

void itoa2(int n, char s[], int w);
void reverse(char s[]);

main()
{
  int n = -123;
  char s[1000];
  int w = 10;

  itoa2(n, s, w);

  printf("%s\n", s);


}




void itoa2(int n, char s[], int w)
{
  int i, sign;

  if (n < 0) {
    sign = -1;
    n = -n;
  } else {
    sign = 1;
  }

  i = 0;

  do {
    s[i++] = n%10 + '0';
  } while ((n /= 10) > 0);

  if (sign == -1)
    s[i++] = '-';

  while (i < w)
    s[i++] = ' ';

  s[i] = '\0';

  reverse(s);
 
}

void reverse(char s[])
{
  int c, i, j;
  for (int i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }


}
