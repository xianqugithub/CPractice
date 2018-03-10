#include <stdio.h>
#define MAXLINE 10

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  int len, c;
  int max = 0;
  char read[MAXLINE];
  char buffer[MAXLINE];
  
  while ((len = getline2(read, MAXLINE)) > 0) {
    if (read[len-1] != '\n') {
      while ((c = getchar()) != EOF) {
	len++;
	if (c == '\n')
	  break;
      }
      
    }

    if (len > max) {
      max = len;
      copy(buffer, read);
    }  
  }

  if (max > 0) {
    printf("Maximum Length: %d\n", max-1);
    printf("%s\n", buffer);
  }
}

int getline2(char line[], int maxline)
{
  int i, c;
  for (i = 0; i < maxline-1 && ((c = getchar()) != EOF) && c != '\n'; i++)
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
