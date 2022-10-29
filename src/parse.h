#ifndef SRC_PARSE_H_
#define SRC_PARSE_H_

int validate_data(const char *stroka);
char *delete_spaces(char *stroka);
char *ParseExpression(char *stroka, int* error);
char *replace_functions(char *stroka);
char *do_spaces(char *stroka);
char* find_and_insert(char* str,char* sub_str, char* sub_str_rep);

#endif  // SRC_PARSE_H_
