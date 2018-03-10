#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
int powerTen(int);


main()
{
  char s1[] = "123.45e-6";
  printf("%2.10f\n", atof(s1));
}



double atof(char s[])
{
  int i, sign, esign;
  int eres = 0;
  double res;
  double pow = 1.0;
  
  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-')? -1:1;

  if (s[i] == '-' || s[i] == '+')
    i++;

  while (isdigit(s[i])) {
    res = 10.0 * res + (s[i++] - '0');
  }

  if (s[i] == '.')
    i++;

  while (isdigit(s[i])) {
    res = 10.0 * res + (s[i++] - '0');
    pow *= 10;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;

  esign = (s[i] == '-')? -1:1;
  
  if (s[i] == '-' || s[i] == '+')
    i++;

  while (isdigit(s[i])) {
    eres = 10 * eres + (s[i++]- '0');
  }

  return (esign == 1)? (sign*res/pow)*powerTen(eres) : (sign*res/pow)/powerTen(eres);

}

int powerTen(int i)
{
  if (i == 0)
    return 1;
  else
    return 10 * powerTen(i-1);
}


