#include <stdio.h>
#include <ctype.h>

void expand(char[], char[]);

main()
{
  char s1[] = "a-z";
  char s2[1000];

  expand(s1, s2);
  printf("%s\n", s2);

  char s3[] = "a-b-c";
  expand(s3, s2);
  printf("%s\n", s2);

  char s4[] = "a-z0-9";
  expand(s4, s2);
  printf("%s\n", s2);

  char s5[] = "-a-z";
  expand(s5, s2);
  printf("%s\n", s2);

  char s6[] = "a-z-";
  expand(s6, s2);
  printf("%s\n", s2);
  
}


void expand(char s1[], char s2[])
{
  int i,j;
  char c;

  for (i = 0; isspace(s1[i]); i++);
  if (s1[i] == '-')
    i++;
  
  j = 0;

  while ((c = s1[i++]) != '\0') {
    if (s1[i] == '-') {
      while (s1[i+2] == '-')
	i += 2;
      for (char k = c; k <= s1[i+1]; k++)
	s2[j++] = k;
      i += 2;
    }

    else
      s2[j++] = c;
  }

s2[j] = '\0';


}
