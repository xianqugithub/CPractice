#include <stdio.h>
#include <string.h>

int strrindex(char[], char[]);

main()
{
  char s[] = "youyou loves mimi.";
  char t[] ="mimi";
  char t2[] = "xx";

  printf("length of s: %lu\n", strlen(s));
  printf("length of t: %lu\n", strlen(t));

  printf("%d\n", strrindex(s,t));
  printf("%d\n", strrindex(s,t2));


}

int strrindex(char s[], char t[])
{
  int i,j,k;
  for (i = strlen(s)-1; i >= strlen(t)-1; i--) {

    for (j = i, k = strlen(t)-1; k >= 0 && s[j] == t[k]; j--, k--)
      ;
    
    if (k == -1)
      return i+1-strlen(t);
  }

  return -1;
  
}
