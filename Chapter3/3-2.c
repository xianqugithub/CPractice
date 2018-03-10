#include <stdio.h>
void escape(char[], char[]);

main()
{
  char s[] = "mimi \t \n is \t not \n good.";
  char t[1000];

  printf("%s\n", s);
  escape(s,t);

  printf("%s\n", t);


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
