#include <stdio.h>
#define TABINC 8
void detab (char *);
void entab (char *);

main(){
  char s[] = "mimizhang\n\tyouyou\nabcdefg      h\n         xianqu";
  printf("original phrase:\n");
  printf("%s\n",s);
  printf("\n");
  detab(s);
  entab(s);
}

void detab(char *s){
  int pos = 1, nb = 0;
  int c;
  while ((c = *s++) != '\0') {
    if (c == '\t') {
      nb = TABINC - (pos-1) % TABINC;
      while (nb > 0) {
	putchar('*');
	nb--;
	pos++;
      }
    } else if (c == '\n') {
	putchar(c);
	pos = 1;
    } else {
	putchar(c);
	pos++;
      }
    
  }
  putchar('\n');
}

void entab(char *s) {
  int c;
  int nb;
  while ((c = *s) != '\0') {
    if (c == ' ') {
      nb = 0;
      while (*s != '\0'&& c == ' ') {
	nb++;
	c = *(++s);
      }

      for (int i = 0; i < nb/TABINC; i++)
	putchar('\t');

      for (int j = 0; j < nb%TABINC; j++)
	putchar('*');
	
    } else {
      putchar(*(s++));
    }

  }
  putchar('\n');

}
