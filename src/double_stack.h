#ifndef SRC_DOUBLE_STACK_H_
#define SRC_DOUBLE_STACK_H_

#include <stdlib.h>

typedef struct double_node {
  struct double_node* next;
  double value;
} double_node;

double_node* d_init(double _value);
double_node* d_push(const double_node** root, double _value);
double d_pop(double_node** root);
void d_destroy(double_node** root);
double d_top(double_node* root);

#endif  // SRC_DOUBLE_STACK_H_
