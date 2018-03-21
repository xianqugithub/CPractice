#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 1000
#define MAXLEN 200
#define BUFSIZE 10000


char *lineptr[MAXLINE];

static char allocbuf[BUFSIZE];
static char *palloc = allocbuf;

int gline(char *, int);
int readlines(char *[], int);
void writelines(char *[], int, int);
char *alloc(int);

int numcmp(char *, char *);
void quicksort(void *[], int, int, int (*comp)(void *, void *));
void swap(void *[], int, int);

main(int argc, char *argv[])
{
  int reverse, numerical, c, nlines;
  reverse = 0, numerical = 0;

  if (argc > 3) {
    printf("Wrong arguments.\n");
    return 0;
  }

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0]) {
      switch(c) {
      case 'n':
	numerical = 1;
	break;
      case 'r':
	reverse = 1;
	break;
      default:
	printf("Wrong argument input.\n");
	return 0;
      }
    }

  if (argc != 0) {
    printf("Usage -n -r for sorting");
    return 0;
  }

  if ((nlines = readlines(lineptr, MAXLINE)) > 0) {
    quicksort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numerical ? numcmp:strcmp));
    writelines(lineptr, nlines, reverse);
    return 1;
  } else
    return 0;
}

int gline(char *line, int lim)
{
  int len, c;
  len = 0;
  while (len < lim-1 && (c = getchar()) != EOF && c != '\n') {
    len++;
    *line++ = c;
  }

  *line = '\0';
  return len;
}

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  
  while ((len = gline(line, MAXLEN)) > 0) {
    if (nlines > maxlines || (p = alloc(len+1)) == NULL) {
      printf("error: storage overflow.\n");
      return 0;
    } else {
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }

  return nlines;
}

char *alloc(int n)
{
  if (allocbuf + BUFSIZE - palloc >= n) {
    palloc += n;
    return palloc - n;
  } else {
    printf("error: no enough space.\n");
    return NULL;
  }

}

void writelines(char *lineptr[], int nlines, int reverse)
{
  int i;
  if (!reverse) {
    for (i = 0; i < nlines; i++) 
      printf("%s\n", lineptr[i]);
  } else {
    for (i = nlines-1; i >=0; i--)
      printf("%s\n", lineptr[i]);
  }

}

void quicksort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int last;
  
  if (left >= right)
    return;

  last = left;

  for (int i = left+1; i <= right; i++) {
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  }

  swap(v, left, last);
  quicksort(v, left, last-1, comp);
  quicksort(v, last+1, right, comp);
}

void swap (void *v[], int i, int j)
{
  void *temp;
  
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
  int n1, n2;
  n1 = atof(s1);
  n2 = atof(s2);

  if (n1 < n2)
    return -1;

  else if (n1 > n2)
    return 1;

  else
    return 0;
}
