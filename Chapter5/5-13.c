#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000
#define ALLOCSIZE 50000
#define DEAFULTLINENO 10

char *lineptr[MAXLINES];

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int gline(char *line, int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int counter);
char *alloc(int n);

main(int argc, char *argv[])
{
  int c, number, nlines, counter;

  if (argc != 2 && argc != 1) {
    printf("Wrong arguments.\n");
    return 0;
  }

  if (argc == 1)
    number = DEAFULTLINENO;
  else if (argc == 2 && (*++argv)[0] == '-') {
    number = atoi(++argv[0]);
  }
  else {
    printf("wrong arguments.\n");
    return 0;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
    counter = nlines < number ? nlines : number;
    writelines(lineptr, nlines, counter);    
  } else {
    printf("Input Error.\n");
    return 0;
  }
}


char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

int gline(char *line, int lim)
{
  int i = 0, c;
  while ((c = getchar()) != EOF && c != '\n' &&  i < lim - 1) {
    line[i++] = c;
  } 
  line[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxline)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = gline(line, MAXLEN)) > 0) {
    if ((nlines > MAXLINES) || (p = alloc(len+1)) == NULL) {
      printf("error: exceeding storage limit.\n");
    } else {
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines, int counter)
{
  while (counter-- > 0) {
    printf("%s\n", lineptr[--nlines]);
  }
}
