#include<stdio.h>

int htoi(char s[]);

main()
{
 printf("%d\n", htoi("7DE"));
 printf("%d\n", htoi("80E1"));
 printf("%d\n", htoi("0xF"));
}

int htoi(char s[])
{
  int i, n;
  n = 0;
  if (s[0] == '0'&& ((s[1] == 'x') || s[1] == 'X'))
    i = 2;
  else
    i = 0;
  
  while ((s[i] >= '0' && s[i] <= '9') ||
	 (s[i] >= 'a' && s[i] <= 'f') ||
	 (s[i] >= 'A' && s[i] <= 'F')) {

	   n *= 16;

	   if (s[i] >= '0' && s[i] <= '9')
	     n += s[i++] - '0';
	   else if (s[i] >= 'a' && s[i] <= 'f')
	     n += s[i++] - 'a' + 10;
	   else
	     n += s[i++] - 'A' + 10;
	 }

	 return n;
}
