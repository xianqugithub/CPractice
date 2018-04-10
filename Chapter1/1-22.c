/* fold the long inputs question */

#include <stdio.h>

#define MAXLEN 20
#define TABINC 2

char buf[MAXLEN];


void printline(int pos);
int findblank(int pos);
int findnewpos(int pos);

int main()
{
  int c, pos, i;

  pos = 0;
  
  while ((c = getchar()) != EOF) {
    buf[pos++] = c;

    if (c == '\t') {
      /* reach the end of the buffer, print out the line */
      /* max buffer index if MALEN - 1 */
      
      if (MAXLEN - pos + 1 <= TABINC) {
	printline(pos-1);
	pos = 0;	
      }

      /* paddle in the blanks */
      else {
	pos--; /* counter back to the position of '\t' for replacement */
	for (i = 0; i < TABINC; i++)
	  buf[pos++] = ' ';
      }
    }

    else if (c == '\n') {
      printline(pos-1);
      pos = 0;
    }

    /* current non-blank character has reached the length limit */
    else if (pos >= MAXLEN) {
      pos = findblank(pos-1);
      printline(pos);
      pos = findnewpos(pos);
    }
   
  }

  return 0;

}

/* print the line before the pos */
void printline(int pos)
{
  int i;
  for (i = 0; i < pos; i++)
    putchar(buf[i]);
  if (pos > 0)
    putchar('\n');
}

/* find the blank position in the buffer */
int findblank(int pos)
{
  while (pos > 0 && buf[pos] != ' ')
    pos--;

  if (pos == 0) /* no blanks in line */
    return MAXLEN;

  return pos+1; /* because printline print one before the posn, non-blank character */

}

/* find the new non-blank position */
int findnewpos(int pos)
{
  int i, j;
  
  /* move to the non-empty buffer position */
  while (buf[pos] == ' ')
    pos++;

  i = 0, j = pos;

  /* copy the rest of the line buffer */
  while (j < MAXLEN)
    buf[i++] = buf[j++];

  return i;
  

}

