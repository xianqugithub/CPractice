#include <stdio.h>


main()
{
  int c;
  int freq[128];
  for (int i = 0; i < 128; i++)
    freq[i] = 0;

  while ((c = getchar()) != EOF) {
    ++freq[c];
  }

  for (int i = 0; i < 128; i++) {
    printf("%c ", i);
    for (int j = 0; j < freq[i]; j++)
      printf("*");
    printf("\n");
  }
  


}

