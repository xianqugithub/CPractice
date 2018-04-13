#include <stdio.h>
#include <string.h>
#include <limits.h>

#define BUFSIZE 50

void itoa_(int n, char s[]);
void reverse(char s[]);

main()
{
  char buf[BUFSIZE];
  itoa_(INT_MAX, buf);

  printf("Maximum: %d\n", INT_MAX);
  printf("String: %s\n", buf);

  itoa_(INT_MIN, buf);
  printf("Min: %d\n", INT_MIN);
  printf("String: %s\n", buf);


}


void itoa_(int n, char s[])
{
  int i, sign;

  sign = (n < 0) ? (-1) : 1;

  i = 0;

  do {
    s[i++] = sign * (n % 10) + '0';
  } while ((n /= 10) != 0);

    if (sign < 0)
      s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[])
{
  int i, j, t;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    t = s[i];
    s[i] = s[j];
    s[j] = t;

  }

}
