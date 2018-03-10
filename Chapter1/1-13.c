#include <stdio.h>
#define IN 1
#define OUT 0

main()
{
  int c, state, nc;
  nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
	for (int i = 0; i < nc; i++)
	  printf("*");
	printf("\n");
	state = OUT;
      }
    }
    
    else {
      if (state == OUT) {
	nc = 1;
	state = IN;
      }

      else
	++nc;
    }
  }



}
