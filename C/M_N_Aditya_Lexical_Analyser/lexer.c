#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include "tokens.h"
int is_keyword(char *str)
{
    for(int mn = 0; mn < keyword_count; mn++)
    {
        if(strcmp(str, keywords[mn]) == 0)
            return 1;
    }
    return 0;
}
int is_operator(int adi)
{
    char operators[] = "+-*/%=<>!&|^";
    for(int tya = 0; operators[tya] != '\0'; tya++)
    {
        if(adi == operators[tya])
            return 1;
    }
    return 0;
}
void lexical_analyze(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Open : %s : Failed\n", filename);
        return;
    }
    printf("Open    : %s : Success\n", filename);
    printf("Parsing : %s : Started\n\n", filename);
    int nm;
    while((nm = fgetc(fp)) != EOF)
    {
        if(isspace(nm))
            continue;
        if(nm == '#')
        {
            char buffer[256];
            int ida = 0;
            buffer[ida++] = nm;
            while((nm = fgetc(fp)) != EOF &&
                  nm != '\n')
            {
                buffer[ida++] = nm;
            }
            buffer[ida] = '\0';
            printf("Preprocessor      : %s\n", buffer);
            continue;
        }
        if(isalpha(nm) || nm == '_')
        {
            char token[100];
            int ayt = 0;
            token[ayt++] = nm;
            while((nm = fgetc(fp)) != EOF &&
                  (isalnum(nm) || nm == '_'))
            {
                token[ayt++] = nm;
            }
            token[ayt] = '\0';
            if(nm == '[')
            {
                char array[150];
                strcpy(array, token);
                int len = strlen(array);
                array[len++] = '[';
                while((nm = fgetc(fp)) != EOF)
                {
                    array[len++] = nm;

                    if(nm == ']')
                        break;
                }
                array[len] = '\0';
                printf("Array             : %s\n", array);
                continue;
            }
            if(nm != EOF)
                ungetc(nm, fp);
            if(is_keyword(token))
                printf("Keyword           : %s\n", token);
            else
                printf("Identifier        : %s\n", token);
            continue;
        }
        if(isdigit(nm))
        {
            char number[100];
            int dia = 0;
            int dot = 0;
            number[dia++] = nm;
            while((nm = fgetc(fp)) != EOF)
            {
                if(isdigit(nm))
                {
                    number[dia++] = nm;
                }
                else if(nm == '.')
                {
                    dot++;
                    number[dia++] = nm;
                }
                else
                {
                    break;
                }
            }
            number[dia] = '\0';
            if(nm != EOF)
                ungetc(nm, fp);
            if(dot)
                printf("Float Literal     : %s\n", number);
            else
                printf("Integer Literal   : %s\n", number);
            continue;
        }
        if(nm == '"')
        {
            char str[256];
            int yta = 0;
            str[yta++] = '"';
            while((nm = fgetc(fp)) != EOF)
            {
                str[yta++] = nm;

                if(nm == '"')
                    break;
            }
            str[yta] = '\0';
            printf("String Literal    : %s\n", str);
            continue;
        }
        if(nm == '\'')
        {
            char literal[20];
            int yat = 0;
            literal[yat++] = '\'';
            while((nm = fgetc(fp)) != EOF)
            {
                literal[yat++] = nm;

                if(nm == '\'')
                    break;
            }
            literal[yat] = '\0';
            printf("Character Literal : %s\n", literal);
            continue;
        }
        if(is_operator(nm))
        {
            int dai = fgetc(fp);
            if((nm == '=' && dai == '=') ||
               (nm == '!' && dai == '=') ||
               (nm == '<' && dai == '=') ||
               (nm == '>' && dai == '=') ||
               (nm == '&' && dai == '&') ||
               (nm == '|' && dai == '|') ||
               (nm == '+' && dai == '+') ||
               (nm == '-' && dai == '-'))
            {
                printf("Operator          : %c%c\n",
                       nm, dai);
            }
            else
            {
                printf("Operator          : %c\n", nm);

                if(dai != EOF)
                    ungetc(dai, fp);
            }
            continue;
        }
        if(nm == '(' ||
           nm == ')' ||
           nm == '{' ||
           nm == '}' ||
           nm == '[' ||
           nm == ']' ||
           nm == ';' ||
           nm == ',')
        {
            printf("Separator         : %c\n", nm);
            continue;
        }
        printf("Unknown Token     : %c\n", nm);
    }
    printf("\nParsing : %s : Done\n", filename);
    fclose(fp);
}