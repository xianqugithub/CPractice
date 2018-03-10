#include<stdio.h>
int any(char[], char[]);
int contains(char[], char);

main()
{
  char s1[] = "youyou loves longlong";
  char s2[] = "l";
  char s3[] = "mimi";

  printf("%d\n", any(s1,s2));
  printf("%d\n", any(s1,s3));
}


int any(char s1[], char s2[])
{
  int i;
  char c;
  
  for (i = 0; (c = s1[i]) != '\0'; i++) {
    if (contains(s2, c))
      return i;
  }
  return -1;
}

int contains(char s[], char c)
{
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == c)
      return 1;
  }
  return 0;
}
