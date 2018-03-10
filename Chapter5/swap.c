#include<stdio.h>
void swap (int *, int *);

main()
{
  int a = 10, b = 100;
  printf("%d %d\n",a,b);

  swap(&a, &b);
  printf("%d %d\n",a,b);

}


void swap(int *px, int *py)
{
  int temp = *px;
  *px = *py;
  *py = temp;
}
