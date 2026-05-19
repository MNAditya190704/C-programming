#include<stdio.h>
int main()
{
    char str[100]="hello world \n";
    printf("%s", str);
    printf("give a string \n");
    scanf("%[^\n]", str);
    printf("%s", str);

    int size;
    printf("giev a string size \n");
    scanf("%d", &size);
    char strr[size];

    for(int i=0; str!='\0'; i++)
    {
        scanf("%c", &strr[i]);
    }
    printf("\n give the index you want \n");
    int a;
    scanf("%d", &a);
    printf("%c", strr[a]);
    for(int i=0; i<=size; i++)
    {
        printf("%c", strr[i]);
    }
}