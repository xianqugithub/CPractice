#include <stdio.h>

void strcat(char *, char*);

main()
{
  char s[] = "mimi";
  char t[] = "loves youyou";
  printf("original: %s\n", s);
  strcat(s,t);
  printf("strcat: %s\n",s);


}

void strcat(char *s, char *t)
{
  while (*s != '\0')
    s++;

  while (*s++ = *t++)
    ;

  
}
