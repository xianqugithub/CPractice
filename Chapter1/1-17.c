#include <stdio.h>
#define MAXLINE 1000
#define MINLENGTH 20


int getlinev2(char buffer[], int maxline);

main()
{
  int c, line;
  char buffer[MAXLINE];
  while ((line = getlinev2(buffer, MAXLINE)) > 0) {
    if (line - 1 > MINLENGTH) {
      printf("length of sentence: %d\n", line-1);
      printf("%s\n", buffer);
    }
   }
}

int getlinev2(char buffer[], int maxline) {
  int i,c;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    buffer[i] = c;
  }

  if (c == '\n')
    buffer[i++] = '\n';

  buffer[i] = '\0';
  return i;

}
