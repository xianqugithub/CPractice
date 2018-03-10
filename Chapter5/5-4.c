#include <stdio.h>

int strend(char *, char *);

main()
{
  char s[] = "mimi loves youyou";
  char y[] = "youyou";
  char n[] = "niaoniao";

  printf("%d\n", strend(s,y));
  printf("%d\n", strend(s,n));
  printf("%d\n", strend(y,n));

}

int strend(char *s, char *t)
{
  int len = 0;

  while (*s)
    s++;

  while (*t) {
    len++;
    t++;
  }

  s--;
  t--;

  while (*s-- == *t--)
    len--;

  return len == 0;
}
