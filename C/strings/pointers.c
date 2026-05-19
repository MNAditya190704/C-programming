#include<stdio.h>
void output(char *str)
{
  printf("%s", str);
}
int main()
{
  char str[]="hi";
  output(str);
}