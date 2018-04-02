#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELIMIT 1000

char linebuf[LINELIMIT];

main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char *s;

  if (argc != 3) {
    printf("Wrong Number of Arguments Given.\n");
  }

  if ((fp1 = fopen(argv[1], "r")) == NULL) {
    printf("Can't open %s.\n", argv[1]);
  }

  if ((fp2 = fopen(argv[2], "r")) == NULL) {
    printf("Can't open %s.\n", argv[2]);
  }

  while (fgets(linebuf, LINELIMIT, fp1) != NULL ) {
    s = strdup(linebuf);
    if (fgets(linebuf, LINELIMIT, fp2) == NULL || strcmp(s, linebuf) != 0) {
      printf("%s\n",s);
      return 0;
    }
  }

  if (fgets(linebuf, LINELIMIT, fp2) != NULL)
    printf("%s\n", linebuf);

  printf("Two files are the same.\n");

  return 1;
}
