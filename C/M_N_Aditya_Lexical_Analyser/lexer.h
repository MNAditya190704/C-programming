#ifndef LEXER_H
#define LEXER_H
void lexical_analyze(const char *filename);
int is_keyword(char *);
int is_identifier(char *);
int is_integer(char *);
int is_float(char *);
#endif