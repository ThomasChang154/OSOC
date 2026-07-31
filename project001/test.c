#include<stdio.h>

int actual_calc(int a, int b)
{
  int c;
  c = a / b;
  return c;
}

int calc()
{
  int a;
  int b;
  a = 13;
  b = 2;
  return actual_calc(a, b);
}

int main()
{
  printf("the result is %d.\n", calc());
  return 0;
}
