#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORDS 100
#define WORDMAX 100


struct tnode
{
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

int size = 0; /* global variable for size of the tlist array*/
char buf = 0; /* buffer of input */

char wordbuf[WORDMAX+1];
struct tnode *tlist[MAXWORDS];

/* IO of the input */
int getword(char *, int);
int getch(void);
void ungetch(int);

/* tree related */
struct tnode *addtree(struct tnode *, char *);
void traverse(struct tnode *);

/* shell sort */
void shellsort(struct tnode *[], int);

int main()
{
 
  struct tnode *root;

  root = NULL;
  
  while (getword(wordbuf, WORDMAX) != EOF) {
    if (isalpha(wordbuf[0]))
      root = addtree(root, wordbuf);
  }
  
  traverse(root); 
  shellsort(tlist, size);

  for (int i = 0; i < size; i++) {
    printf("%s:%d\n", tlist[i]->word, tlist[i]->count);
  }

  return 0;
}

int getword(char *buf, int lim)
{
  int c;
  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *buf++ = c;
  if (!isalpha(c)) {
    *buf = '\0';
    return c;
  }

  for (; --lim > 0; buf++)
    if (!isalpha(*buf = getch())) {
      ungetch(*buf);
      break;
    }

  *buf = '\0';

  return buf[0];
}

int getch()
{
  int t;

  if (buf == 0)
    return getchar();
  
  t = buf;
  buf = 0;
  return t;
}

void ungetch(int c)
{
  buf = c;
}



struct tnode *addtree(struct tnode *root, char *w)
{
  int cond;
  
  if (root == NULL) {
    root = (struct tnode *) malloc (sizeof(struct tnode));
    root->word = strdup(w);
    root->count = 1;
    root->left = root->right = NULL;
  } else if ((cond = strcmp(w, root->word)) == 0)
    root->count++;
  else if (cond > 0)
    root->right = addtree(root->right, w);
  else
    root->left = addtree(root->left, w);

  return root;
}

void traverse(struct tnode *root)
{
  if (root != NULL) {
    traverse(root->left);
    tlist[size++] = root;
    traverse(root->right);
  }
}

void shellsort(struct tnode *tlist[], int n)
{
  int gap, i, j;
  struct tnode *temp;

  for (gap = n/2; gap > 0; gap/=2)
    for (i = gap; i < n; i++)
      for (j = i-gap; j >=0 && tlist[j]->count > tlist[i]->count; j -= gap) {
	temp = tlist[i];
	tlist[i] = tlist[j];
	tlist[j] = temp;
      }
}





  
