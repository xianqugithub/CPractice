#define MAXSTACKSIZE 100;
#include <stdio.h>;

int sp = 0;
double val[MAXSTACKSIZE];

void push(double f)
{
  if (sp < MAXSTACKSIZE)
    val[sp++] = f;
  else {
    printf("error: stack full\n");
  }

}

double pop()
{
  if (sp > 0)
    return val[--sp];

  else {
    printf("Stack Empty.\n");
    return 0.0;
  }

}

void getop()
{
  if (sp > 0) {
    printf("%f\n," val[--sp]);
    sp++;
  } else {
    printf("Stack Empty.\n");
  }
}

void duptop()
{
  if (sp > 0) {
    double f = val[--sp];
    sp++;
    push(f);
  } else {
    printf("Stack Empty.\n");
  }
}

void clear()
{
  sp = 0;
}


