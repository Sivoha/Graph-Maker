#include "operations_processing.h"

#include <math.h>

int IsBinary(char operation) {
  return (operation == '+' || operation == '-' || operation == '*' ||
          operation == '/' || operation == '^');
}

int IsPrefix(char operation) {
  return (operation == 's' || operation == 'c' || operation == 't' ||
          operation == 'k' || operation == 'l' || operation == 'g' ||
          operation == '~');
}

int CmpPriority(char first, char second) {
  int result = 0;
  if (first == '^') {
    result = 1;
  } else if (first == '~') {
    result = (second != '^');
  } else if (first == '*' || first == '/') {
    result = ((second != '^') && (second != '~'));
  } else if (first == '+' || first == '-') {
    result = (second == '-' || second == '+');
  }

  return result;
}

double binary_operation_result(char operation, double first_operand,
                               double second_operand) {
  double result = 0;

  if (operation == '+') {
    result = first_operand + second_operand;
  } else if (operation == '-') {
    result = second_operand - first_operand;
  } else if (operation == '*') {
    result = first_operand * second_operand;
  } else if (operation == '/') {
    result = second_operand / first_operand;
  } else if (operation == '^') {
    result = pow(second_operand, first_operand);
  }

  return result;
}

double prefix_operation_result(char operation, double operand) {
  double result = 0;

  if (operation == 's') {
    result = sin(operand);
  } else if (operation == 'c') {
    result = cos(operand);
  } else if (operation == 't') {
    result = tan(operand);
  } else if (operation == 'g') {
    result = 1 / tan(operand);
  } else if (operation == 'k') {
    result = sqrt(operand);
  } else if (operation == 'l') {
    result = log(operand);
  } else if (operation == '~') {
    result = -1 * operand;
  }

  return result;
}
