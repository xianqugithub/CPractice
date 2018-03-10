#include <stdio.h>
#include <limits.h>

main()
{
  printf("Maximum of unsigned char: %u\n", (unsigned char) (~0));
  printf("Maximum of unsigned short: %u\n", (unsigned short) (~0));
  printf("Maximum of unsgined int: %u\n", (unsigned int) (~0));
  printf("Maximum of unsigned long: %lu\n", (unsigned long) (~0));
  printf("Maximum of unsigned long: %lu\n", ULONG_MAX);
  printf("********\n");

  printf("Maximum of signed char: %d\n", CHAR_MAX);
  printf("Minimum of signed char: %d\n", CHAR_MIN);
  printf("********\n");
printf("Maximum of signed short: %d\n", SHRT_MAX);
printf("Minimum of signed short: %d\n", SHRT_MIN);

printf("Maximum of signed int: %d\n", INT_MAX);
printf("Minimum of signed int: %d\n", INT_MIN);

printf("Maximum of signed int: %ld\n", LONG_MAX);
printf("Minimum of signed int: %ld\n", LONG_MIN);
}
