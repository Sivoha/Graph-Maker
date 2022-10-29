#include "stack.h"

#include <stdlib.h>
#include <string.h>

node *init(char *_value) {
  node *root = (node *)malloc(sizeof(node));
  root->value = malloc(strlen(_value) * sizeof(char));
  root->next = NULL;
  strcpy(root->value, _value);
  return root;
}

node *push(const node **root, char *_value) {
  node *tmp = (node *)malloc(sizeof(node));
  tmp->value = malloc(strlen(_value) * sizeof(char));
  tmp->next = (node *)*root;
  strcpy(tmp->value, _value);

  return tmp;
}

char *pop(node **root) {
  char *res = NULL;
  if (*root != NULL) {
    res = malloc(strlen((*root)->value) * sizeof(char));
    strcpy(res, (*root)->value);
    node *tmp = (*root)->next;
    free((*root)->value);
    free(*root);
    *root = tmp;
  }
  return res;
}

char *top(node *root) {
  if (root == NULL) {
    return NULL;
  }
  return root->value;
}

void destroy(node **root) {
  while (strcmp(top(*root), "NULL") != 0) {
    free(pop(root));
  }
  free((*root)->value);
  free(*root);
}
