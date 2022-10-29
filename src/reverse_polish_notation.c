#include "reverse_polish_notation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "double_stack.h"
#include "operations_processing.h"
#include "stack.h"

char *ExpressionToRPN(char *expression) {
  char *output = malloc(strlen(expression) * sizeof(char));
  strcpy(output, "");
  node *operations = init("NULL");
  char *token = strtok(expression, " ");
  while (token != NULL) {
    if ((strlen(token) != 1) || ((token[0] >= '0') && (token[0] <= '9')) ||
        (token[0] == 'x')) {
      strcat(output, token);
      strcat(output, " ");
    } else {
      if (token[0] == ')') {
        while (strcmp(top(operations), "(") != 0) {
          CatToOutput(&operations, &output);
        }
        free(pop(&operations));
      } else if (IsBinary(token[0]) == 1) {
        if (strcmp(top(operations), "NULL") != 0) {
          while (((IsPrefix(top(operations)[0]) == 1) &&
                  (top(operations)[0] != '~')) ||
                 (CmpPriority(top(operations)[0], token[0]) > 0)) {
            CatToOutput(&operations, &output);
          }
        }
      }
      if (token[0] != ')') {
        operations = push((const node **)&operations, token);
      }
    }
    token = strtok(NULL, " ");
  }
  while (strcmp(top(operations), "NULL") != 0) {
    CatToOutput(&operations, &output);
  }

  destroy(&operations);
  return output;
}

void CatToOutput(node **operations, char **output) {
  char *temp = pop(operations);
  strcat(*output, temp);
  free(temp);
  strcat(*output, " ");
}

double RPNToValue(char *RPN, double x) {
  double result;
  char *token = strtok(RPN, " ");
  double_node *stack;

  if (token[0] == 'x') {
    stack = d_init(x);
  } else {
    stack = d_init(atof(token));
  }

  token = strtok(NULL, " ");
  double first_operand, second_operand;

  while (token != NULL) {
    if ((strlen(token) != 1) || ((token[0] >= '0') && (token[0] <= '9')) ||
        (token[0] == 'x')) {
      if ((strlen(token) != 1) || ((token[0] >= '0') && (token[0] <= '9'))) {
        stack = d_push((const double_node **)&stack, atof(token));
      } else {
        stack = d_push((const double_node **)&stack, x);
      }
    } else if ((strlen(token) == 1) && ((token[0] < '0') || (token[0] > '9'))) {
      if (IsBinary(token[0])) {
        first_operand = d_pop(&stack);
        second_operand = d_pop(&stack);
        stack = d_push(
            (const double_node **)&stack,
            binary_operation_result(token[0], first_operand, second_operand));
      } else if (IsPrefix(token[0])) {
        first_operand = d_pop(&stack);
        stack = d_push((const double_node **)&stack,
                       prefix_operation_result(token[0], first_operand));
      }
    }

    token = strtok(NULL, " ");
  }

  result = d_pop(&stack);
  return result;
}
