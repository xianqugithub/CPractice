#include<stdio.h>

unsigned setbits(unsigned, int, int, unsigned);
unsigned invert(unsigned, int, int);
int rightrot(int, int);
void bin(unsigned);

main()
{
  unsigned x = 100;
  bin(x);
  unsigned y = 90;
  bin(y);
  unsigned r = setbits(x, 4, 2, y);
  bin(r);
  unsigned i = invert(x, 4, 2);
  bin(i);

  int a = 100;
  bin(a);
  int b = rightrot(a, 4);
  bin(b);

}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  //right most of x to be perserved
  unsigned r = x & ~( ~ 0 << (p-n+1));
  //right most of y to be added
  unsigned a = y & ~ (~ 0 << n);

  return ((((x >> (p+1)) << n) + a) << (p-n+1)) + r;
}

unsigned invert(unsigned x, int p, int n)
{
  unsigned r = x & ~(~0 << (p-n +1));
  unsigned m = (~x >> (p-n+1) & ~(~0 << n));

  return ((((x >> (p+1)) << n) + m) << (p-n+1)) + r;
}

int rightrot(int x, int n)
{
  int r = x >> n;
  int l = (x & ~ (~ 0 << n)) << (32-n);
  return l + r;
}


void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2) {
      (n & i)? printf("1"): printf("0");
    }
    printf("\n");
}
