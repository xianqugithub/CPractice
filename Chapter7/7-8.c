#include <stdio.h>
#include <stdlib.h>

#define PAGELINE 20 /* Number of lines per page. */
#define LINELIMIT 1000 /* Line limit for each file */

void printfile(FILE *fp, char *name);
void printheader(char *name, int pageno);

main(int argc, char *argv[])
{
  FILE *fp;

  if (argc == 1) {
    fprintf(stderr, "No Input File.\n");
    exit(1);
  }

  while (--argc > 0) {
    if ((fp = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "%s cannot be opened.\n", *argv);
      exit(2);
    } else {
      printfile(fp, *argv);
      fclose(fp);
    }
  }

  return 0;
}

void printfile(FILE *fp, char *name)
{
  int pageno, lineno;
  char linebuf[LINELIMIT];
  
  pageno = 1;
  printheader(name, pageno++);
  lineno = 4;

  while ((fgets(linebuf, LINELIMIT, fp)) != NULL) {
    if (lineno == PAGELINE-2 ) {
      printf("\n\n");
      printheader(name, pageno++);
      lineno = 4;
    }

    fputs(linebuf, stdout);
    lineno++;
  }
  
}

void printheader(char *name, int pageno)
{
  printf("File: %s\n", name);
  printf("Page: %d\n", pageno);
  printf("\n\n");

}
