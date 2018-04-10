#include<stdio.h>

/* Verify getchar() != EOF is 0 or 1*/
main(){
  int c;
  while (c = getchar() != EOF) {
    printf("%d\n", c);
  }

  printf("%d\n", c);
  
}
