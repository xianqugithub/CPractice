#include <stdio.h>
#define BUFSIZE 1000

void escape(char[], char[]);
void unescape(char[], char[]);

main()
{
  char s[] = "mimi \t \n is \t not \n good.";
  char t[BUFSIZE];
  char u[BUFSIZE];

  printf("%s\n", s);
  
  escape(s,t);
  printf("%s\n", t);

  unescape(t, u);
  printf("%s\n", u);

}


void escape(char s[], char t[])
{
  int i, j;
  for (j = i = 0; s[i] != '\0'; i++) {
    switch(s[i]) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    case ' ':
      t[j++] = '\\';
      t[j++] = 'b';
      break;
      
    default:
      t[j++] = s[i];
    }
  }

  t[j] = '\0';

}

void unescape(char s[], char t[])
{
  int i, j;
  for (j = i = 0; s[i] != '\0'; i++) {
    switch(s[i]) {
    case '\\':
      switch(s[++i]) {
      case 'n':
	t[j++] = '\n';
	break;
      case 't':
	t[j++] = '\t';
	break;
      case 'b':
	t[j++] = ' ';
	break;
      }
      break;

    default:
      t[j++] = s[i];
      break;
    }
  }

  t[j] = '\0';


}
