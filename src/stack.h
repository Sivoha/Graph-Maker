#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdlib.h>

typedef struct node {
  struct node* next;
  char* value;
} node;

node* init(char* _value);
node* push(const node** root, char* _value);
char* pop(node** root);
void destroy(node** root);
char* top(node* root);
#endif  // SRC_STACK_H_
