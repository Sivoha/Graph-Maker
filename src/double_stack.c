#include "double_stack.h"

#include <stdlib.h>

double_node *d_init(double _value) {
  double_node *root = (double_node *)malloc(sizeof(double_node));
  root->value = _value;
  root->next = NULL;
  return root;
}

double_node *d_push(const double_node **root, double _value) {
  double_node *tmp = (double_node *)malloc(sizeof(double_node));
  tmp->value = _value;
  tmp->next = (double_node *)*root;

  return tmp;
}

double d_pop(double_node **root) {
  double res = 0;
  if (*root != NULL) {
    res = (*root)->value;
    double_node *tmp = (*root)->next;
    free(*root);
    *root = tmp;
  }
  return res;
}
