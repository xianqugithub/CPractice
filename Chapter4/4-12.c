#include <stdio.h>

int bufp = 0;

void itoarec(int, char []);

main()
{
  char s[100];
  itoarec(1234567, s);
  printf("%s\n", s);


}


void itoarec(int n, char buf[])
{
  if (n < 0) {
    buf[bufp++] = '-';
    n = -n;
  }
  if (n / 10)
    itoarec(n / 10, buf);
  buf[bufp++] = n % 10 + '0';
  buf[bufp] = '\0';
}
