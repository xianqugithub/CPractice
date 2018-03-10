#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void trailing(char s[], int len);
int getline2(char read[], int maxline);

main()
{
  int len;
  char buffer[MAXLINE];

  while ((len = getline2(buffer, MAXLINE)) > 0) {
    printf("original len: %d\n", len-1);
    trailing(buffer, len);
    printf("%s\n", buffer);
    printf("trailing len: %d\n", strlen(buffer));
  }
}

int getline2(char read[], int lim)
{
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    read[i] = c;
    printf("%d %c\n", i, read[i]);
  }

  if (c == '\n') {
    read[i++] = '\n';
    printf("%d %c\n", i-1, read[i-1]);
  }

  read[i] = '\0';
  printf("%d %c\n", i, read[i]);

  return i;

}

void trailing(char s[], int len)
{
  int i = len-2;
  while ( i >= 0 && (s[i] == '\t' || s[i] == ' ')) 
    i--;
  s[i+1] = '\0';
}
