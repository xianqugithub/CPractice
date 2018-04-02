#include <stdio.h>
#include <ctype.h>
#include <string.h>

main(int argc, char *argv[])
{
  int c;
  
  if (argc > 1) {
    printf("Wrong Number of Arguments.\n");
    return 0;
  }

  if (strcmp(argv[0], "./lower") == 0) {
    while ((c = getchar()) != EOF)
      putchar(tolower(c));
  } else {
    while ((c= getchar()) != EOF)
      putchar(toupper(c));
  }

  return 1;
}
