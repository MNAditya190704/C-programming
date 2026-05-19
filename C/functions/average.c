#include<stdio.h>
void average(int a, int b, int c)
{
    printf("%d", (a+b+c)/3);
}
int main()
{
  int x, y, z;
  printf("give 3 numbers");
  scanf("%d %d %d", &x, &y, &z);
  average(x, y, z);
}