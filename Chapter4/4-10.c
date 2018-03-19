#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define MAXOP 100
#define NUMBER '0'
#define STACKSIZE 1000


int gline(char *, int);
int getop(char *, char *);
double pop();
void push(double);

int li; /* line index */
int sp = 0;
double stack[STACKSIZE]; /* stack */

main()
{
  int type;
  double res;
  char linebuf[MAXLINE], opbuf[MAXOP];
  double op2;

  while (gline(linebuf, MAXLINE) > 0) {
    /* reset the line index */
    res = 0.0;
    li = 0;
    while ((type = getop(linebuf, opbuf)) != '\0'){
      switch(type) {
      case NUMBER:
	push(atof(opbuf));
	break;
      case '+':
	push(pop() + pop());
	break;
      case '*':
	push(pop() * pop());
        break;
      case '-':
	op2 = pop();
	push(pop() - op2);
	break;
      case '/':
	op2 = pop();
	if (op2 != 0.0)
	  push(pop() / op2);
	else
	  printf("error: Zero divisor\n");
	break;
      default:
	printf("error: Unknown command\n");
	break;
      }

    }

    res = pop();

    printf("Result is:%f\n", res);
    
  }
  
}


int gline(char *s, int lim)
{
  int i = 0, c;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
    i++;
  }
  *s = '\0';
  return i;
}

int getop(char *s, char *t)
{
  int c;

  if (li == strlen(s))
    return '\0';

  while (s[li] == ' ')
    li++;

  if (!isdigit(s[li]))
    return s[li++];

  while (isdigit(s[li])) {
    *t++ = s[li++];
  }

  if (s[li] == '.') {
    *t++ = s[li++];
    while (isdigit(s[li]))
      *t++ = s[li++];
  }

  *t = '\0';

  return NUMBER;
}

double pop()
{
  if (sp == 0) {
    printf("error: empty stack.\n");
    return 0.0; 
  } else {
    return stack[--sp];
  }

}

void push(double f)
{
  if (sp == STACKSIZE) {
    printf("error: stack full.\n");
  } else {
    stack[sp++] = f;
  }

}


