#include <stdio.h>
#define MAXLINE 1000

int getline2(char buffer[], int lim);
void reverse(char s[]);

main ()
{
  int len;
  char buffer[MAXLINE];
  while ((len = getline2(buffer, MAXLINE)) > 0) {
    if (len > 0) {
      reverse(buffer);
      printf("%s\n", buffer);
    }
  }
}

int getline2(char buffer[], int lim) {
  int c, i;
  for (i = 0; ((c = getchar()) != EOF) && c != '\n'; i++)
    buffer[i] = c;
  if (c == '\n')
    buffer[i++] = '\n';
  buffer[i] = '\0';
  return i;
}


void reverse(char s[])
{
  int i = 0;
  int j;
  
  for (j = 0; s[j] != '\n'; j++);

  while (i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }

}

