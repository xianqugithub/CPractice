#include <stdio.h>
int day_of_year(int, int, int);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

main()
{
  int year = 1986, month = 6, day = 6;
  printf("%d\n", day_of_year(year, month, day));

  int yearday = 157;
  int pmonth, pday;
  month_day(year, yearday, &pmonth, &pday);

  printf("%d\n", pmonth);
  printf("%d\n", pday);

  
}


int day_of_year (int year, int month, int day)
{
  int i, leap;
  
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

  char *p = daytab[leap];

  for (i = 1; i < month; i++) {
    day += *++p;
  }
  
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i = 1;
  int leap;
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

  char *p = daytab[leap];
  p++;

  while (yearday > *p) {
    yearday -= *(p++);
    i++;
  }

  *pmonth = i;
  *pday = yearday;
  
}
