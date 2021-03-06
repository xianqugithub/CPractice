#include <stdio.h>
int bitcount(unsigned);
void bin(unsigned);

main()
{
  unsigned a = 115;
  bin(a);
  printf("number of bits: %d\n", bitcount(a));
}


int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x &= (x-1))
    b++;
  return b;
}


void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2) {
      (n & i)? printf("1"): printf("0");
    }
    printf("\n");
}
