#include<stdio.h>
#include<string.h>
void read(int m, int n, char str[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
    {
        scanf(" %[^\n]", &str[i]);
    }
}
void print(int m, int n, char str[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
    {
        printf("%s", str[i]);
    }
}
int main()
{
    int m, n;
    printf("give number of strings and substrings");
    scanf("%d %d", &m, &n);
    char str[m][n];
    read(m, n, str);
    print(m, n, str);
}