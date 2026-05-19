#include<stdio.h> 
#include<string.h>

void combination(char [],int ,int );
int is_distinct(char []);

char original[100];   

int main()
{
        char str[100];
        int n;

        // printf("Enter a string: ");
        scanf("%s",str);    

        if(!is_distinct(str))
        {
                printf("Error: please enter distinct characters.");
                return 0;
        }

        strcpy(original,str);   

        n = strlen(str);

        printf("\nAll possible combinations of given string :%s\n",str);

        combination(str,0,n-1);                       

        return 0;
}

int is_distinct(char str[])
{
        int i,j;

        for(i = 0; str[i] != '\0'; i++)
        {
                for(j = i + 1; str[j] != '\0'; j++)
                {
                        if(str[i] == str[j])
                                return 0;
                }
        }
        return 1;
}

void combination(char str[],int l,int r)
{
        int i;

        if(l == r)
        {
                if(strcmp(str, original) != 0)   // skip original
                        printf("%s\n",str);
                return;
        }

        for(i = l; i <= r; i++)
        {
                swap(&str[l], &str[i]);
                combination(str, l + 1, r);
                swap(&str[l], &str[i]);   
        }
}

void swap(char *a,char *b)
{
        char temp = *a;
        *a = *b;
        *b = temp;
}